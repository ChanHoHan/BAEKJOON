//2748
#include <iostream>
#define endl "\n"
int n;

long long dp[91];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> n;
}

void solve()
{
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2 ; i <= 90 ; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	std::cout << dp[n];
}

int main()
{
	input();
	solve();
	return (0);
}

