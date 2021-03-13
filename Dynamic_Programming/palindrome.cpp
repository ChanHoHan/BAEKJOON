//10942
#include <iostream>
#include <vector>
#define endl "\n"

int N, M, S, E;
std::vector<int> board;
std::vector<std::vector<int> > dp;

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> N;
	board.resize(N + 1);
	dp.resize(N + 1, std::vector<int>(N + 1, -1));
	for (size_t i = 1 ; i <= N ; i++)
		std::cin >> board[i];
	std::cin >> S;
}

bool dfs(int x, int y)
{
	if (board[x] != board[y] || !dp[x][y])
		return (0);
	if (dp[x][y] == 1)
		return (1);
	if (x >= y - 1)
	{
		dp[x][y] = 1;
		return (1);
	}
	if (dfs(x + 1, y - 1))
		dp[x][y] = 1;
	else
		dp[x][y] = 0;
	return (dp[x][y]);
}

void solve()
{
	int a, b;

	while (S--)
	{
		std::cin >> a >> b;
		if (dp[a][b] == 1)
			std::cout << dp[a][b] << endl;
		else
		{
			dfs(a, b);
			std::cout << dp[a][b] << endl;
		}
	}
}

int main()
{
	input();
	solve();
	return (0);
}

