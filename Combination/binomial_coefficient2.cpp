//11051
#include <iostream>
int N, K;
int dp[1001][1001];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> N >> K;
}

int nCr(int n, int r)
{
	if (dp[n][r])
		return (dp[n][r]);
	if (r == 0)
		return (1);
	if (n < r)
		return (0);
	dp[n][r] = (nCr(n - 1, r - 1) + nCr(n - 1, r)) % 10007;
	return dp[n][r];
}

void solve()
{
	std::cout << nCr(N, K);
}

int main()
{
	input();
	solve();
	return (0);
}
