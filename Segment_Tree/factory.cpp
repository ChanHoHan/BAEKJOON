#include <iostream>

int N;
int table[1000002];
int tree[1000009];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	int inp;

	io_faster();
	std::cin >> N;
	for (int i = 0 ; i < N ; i++) {
		std::cin >> inp;
		table[inp] = i;
	}
}

int seg_sum(int a, int b)
{
	int ans = 0;

	for (a += N , b += N ; a < b ; a >>=1 , b >>=1) {
		if (a & 1) ans += tree[a++];
		if (b & 1) ans += tree[--b];
	}
	return (ans);
}

void update_tree(int n)
{
	n += N;
	tree[n] = 1;

	for ( ;n > 1 ; n >>= 1) {
		tree[n >> 1] = tree[n] + tree[n ^ 1];
	}
}

void solve()
{
	int inp;
	long long ans = 0;

	for (int i = 0 ; i < N ; i++) {
		std::cin >> inp;
		ans += seg_sum(table[inp] + 1, N);
		update_tree(table[inp]);
	}
	std::cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}

