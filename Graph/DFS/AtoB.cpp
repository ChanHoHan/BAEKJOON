//16953
#include <iostream>
#include <algorithm>

long long A, B;
int ans = 1e9 + 1;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> A >> B;
}

void dfs(long long val, int depth)
{
	if (val > 1e9)
		return;
	if (val == B)
	{
		ans = std::min(ans, depth + 1);
		return;
	}
	dfs(val * 2, depth + 1);
	dfs(10 * val + 1, depth + 1);
}

void solve()
{
	dfs(A, 0);
}

void print_val()
{
	if (ans == 1e9 + 1)
		std::cout << -1;
	else
		std::cout << ans;
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}

