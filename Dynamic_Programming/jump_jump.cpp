//11060
#include <iostream>
#include <algorithm>

int N, ans;
int A[1001];
int dp[1001];

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
	for (int i = 0 ; i < N ; i++)
		std::cin >> A[i];
	std::fill(dp, dp + 1001, 999999999);
}

void solve()
{
	int tmp, j, val;

	dp[0] = 0;
	for (int i = 0 ; i < N ; i++)
	{
		if (dp[i] == 999999999)
			continue;
		tmp = A[i];
		val = dp[i];
		j = 1;
		while (i + j < N && j <= tmp)
		{
			dp[i + j] = std::min(dp[i + j], val + 1);
			j++;
		}
	}
	ans = dp[N - 1];
	if (ans == 999999999)
		ans = -1;
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
