//2133
#include <iostream>
int N, dp[31];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> N;
}

void solve()
{
	dp[0] = 1;
	dp[2] = 3;
	for (int i = 4 ; i <= N ; i++)
	{
		if (i % 2)
			continue;
		dp[i] = 3 * dp[i - 2];
		for (int j = i - 4 ; j >= 0 ; j-=2)
			dp[i] += 2 * dp[j];
	}
	std::cout << dp[N];
}

int main()
{
	input();
	solve();
	return (0);
}
