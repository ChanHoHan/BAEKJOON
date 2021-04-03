//2805
#include <iostream>
#include <vector>
typedef long long ll;

int N, M, max_height;
size_t _N;
std::vector<int> trees_height;
int ans;

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> N >> M;
	trees_height.resize(N);
	_N = N;
	for (int i = 0 ; i < _N ; i++)
	{
		std::cin >> trees_height[i];
		if (max_height < trees_height[i])
			max_height = trees_height[i];
	}
}

ll cal_cutted_trees(ll mid)
{
	ll length = 0;

	for (size_t i = 0 ; i  < _N ; i++)
		if (trees_height[i] > mid)
			length += trees_height[i] - mid;
	return (length);
}

void binary_search(ll b_left, ll b_right)
{
	if (b_left > b_right)
		return ;
	ll mid = (b_left + b_right) / 2;
	ll cal = cal_cutted_trees(mid);
	if (cal >= M && ans < mid)
		ans = mid;
	if (cal > M)
		binary_search(mid + 1, b_right);
	else
		binary_search(b_left, mid - 1);
}

void solve()
{
	binary_search(1, max_height);
}

void print_val()
{
	std::cout << ans;
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}

