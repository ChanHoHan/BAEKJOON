#include <iostream>
#define endl "\n"

int M, N, g_map[251][251], visited[251][251], ans;
int dy[8] = {0,1,1,1,0,-1,-1,-1};
int dx[8] = {1,1,0,-1,-1,-1,0,1};

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> M >> N;
	for (int i = 0 ; i < M ; i++)
		for (int j = 0 ; j< N ; j++)
			std::cin >> g_map[i][j];
}

void dfs(int y, int x)
{
	int ny, nx;

	for (int i = 0 ; i < 8 ; i++)
	{
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || ny >= M || nx < 0 || nx >= N || visited[ny][nx] || !g_map[ny][nx])
			continue;
		visited[ny][nx] = 1;
		dfs(ny, nx);
	}
}

void solve()
{
	for (int i = 0 ; i < M ; i++)
		for (int j = 0 ; j < N ; j++)
			if (g_map[i][j] && !visited[i][j])
			{
				visited[i][j] = 1;
				dfs(i, j);
				ans++;
			}
	std::cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}

