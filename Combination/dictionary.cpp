//1256
#include <iostream>
#include <string>

#define INF 1000000010

int N, M, K;
int dp[101][101];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> N >> M >> K;
	for (int i = 0 ; i <= 100 ; i++)
		for (int j = 0 ; j <= 100 ; j++)
			dp[i][j] = -1;
}

int getAZ(int a, int z)
{
	if (a == 0 || z == 0)
		return (1);
	if (dp[a][z] != -1)
		return (dp[a][z]);
	dp[a][z] = getAZ(a - 1 , z) + getAZ(a, z - 1);
	if (dp[a][z] >= INF)
		dp[a][z] = INF;
	return (dp[a][z]);
}

void solve()
{
	int countA = N , countZ = M,  tmp;

	if (getAZ(N, M) < K)
	{
		std::cout << -1;
		return;
	}
	std::string ans;
	ans.resize(N + M);
	for (int i = 0 ; i < N + M ; i++)
	{
		if (countA > 0)
		{
			tmp = getAZ(countA - 1, countZ);
			if (tmp < K) 
			{
				ans[i] = 'z';
				K -= tmp;
				countZ--;
			}
			else
			{
				ans[i] = 'a';
				countA--;
			}
		}
		else
			ans[i] = 'z';
	}
	for (int i = 0 ; i < N + M ; i++)
		std::cout << ans[i];
}

int main()
{
	input();
	solve();
	return (0);
}
