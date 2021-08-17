#include <iostream>
#include <algorithm>

#define endl "\n"
int N, M, a, b;
int arr[100002];
std::pair<int, int> tree[200009];//max, min

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void search_tree(int a, int b)
{
	int max_ = -1, min_ = 1e9 + 9;
	for (a += N, b += N ; a < b; a >>= 1, b >>= 1)
	{
		if (a & 1) {
			max_ = std::max(max_, tree[a].first);
			min_ = std::min(min_, tree[a].second);
			a++;
		}
		if (b & 1) {
			--b;
			max_ = std::max(max_, tree[b].first);
			min_ = std::min(min_, tree[b].second);
		}
	}
	std::cout << min_ << " " << max_ << endl;
}

void init_tree()
{
	for (int i = N ; i < 2 * N ; i++)
	{
		tree[i].first = arr[i - N + 1];
		tree[i].second = arr[i - N + 1];
	}
	for (int i = N - 1 ; i >= 1 ; i--)
	{
		tree[i].first = std::max(tree[i << 1].first, tree[i << 1 | 1].first);
		tree[i].second = std::min(tree[i << 1].second, tree[i << 1 | 1].second);
	}
}

void input()
{
	io_faster();
	std::cin >> N >> M;
	for (int i = 1 ; i <= N ; i++)
		std::cin >> arr[i];
}

void solve()
{
	init_tree();
	for (int i = 0 ; i < M ; i++)
	{
		std::cin >> a >> b;
		search_tree(a - 1, b);
	}
}

int main()
{
	input();
	solve();
	return (0);
}

