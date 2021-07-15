//12865
#include <iostream>
#include <algorithm>

typedef std::pair<int, int> pii;

int N, K;
pii knapsack[101];
int dp[100001][101];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	int  W, V;

	io_faster();
	std::cin >> N >> K;
	for (int i = 1 ; i <= N ; i++)
	{
		std::cin >> W >> V; 
		knapsack[i].first = W;
		knapsack[i].second = V;
	}
}

void solve()
{
	for (int i = 1 ; i <= K ; i++)
	{
		for (int j = 1 ; j <= N ; j++)
		{
			int W = knapsack[j].first;
			int V = knapsack[j].second;
			if (i >= W)
				dp[i][j] = std::max(dp[i][j - 1], dp[i - W][j-1] + V);
			dp[i][j] = std::max(dp[i][j - 1], dp[i][j]);
		}
	}
	std::cout << dp[K][N];
}

int main()
{
	input();
	solve();
	return (0);
}

