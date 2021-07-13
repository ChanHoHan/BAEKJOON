//3187
#include <iostream>
#include <vector>

int R, C;
char g_map[251][251];
bool visited[251][251];
typedef std::pair<int, int> pii;
std::vector<pii> sheep;
std::vector<pii> wolf;
int sheep_cnt, wolf_cnt;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int dfs_sheep, dfs_wolf;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> R >> C;
	for (int i = 0 ; i < R ; i++)
	{
		std::cin >> g_map[i];
		for (int j = 0 ; j < C ; j++)
		{
			if (g_map[i][j] == 'k')
				sheep.push_back({i, j});
			else if (g_map[i][j] == 'v')
				wolf.push_back({i, j});
		}
	}
	sheep_cnt = sheep.size();
	wolf_cnt = wolf.size();
}

void dfs(int y, int x)
{
	int ny, nx;

	for (int i = 0 ; i < 4 ; i++)
	{
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx] || g_map[ny][nx] == '#')
			continue;
		if (g_map[ny][nx] == 'k')
			dfs_sheep++;
		else if (g_map[ny][nx] == 'v')
			dfs_wolf++;
		visited[ny][nx] = 1;
		dfs(ny, nx);
	}
}

void solve()
{
	int s_size = sheep.size(), w_size = wolf.size();

	for (int i = 0 ; i < s_size ; i++)
	{
		if (!visited[sheep[i].first][sheep[i].second])
		{
			dfs_sheep = 1, dfs_wolf = 0;
			visited[sheep[i].first][sheep[i].second] = 1;
			dfs(sheep[i].first, sheep[i].second);
			if (dfs_sheep > dfs_wolf)
				wolf_cnt -= dfs_wolf;
			else
				sheep_cnt -= dfs_sheep;
		}
	}
	for (int i = 0 ; i < w_size ; i++)
	{
		if (!visited[wolf[i].first][wolf[i].second])
		{
			dfs_sheep = 0, dfs_wolf = 1;
			visited[wolf[i].first][wolf[i].second] = 1;
			dfs(wolf[i].first, wolf[i].second);
			if (dfs_sheep > dfs_wolf)
				wolf_cnt -= dfs_wolf;
			else
				sheep_cnt -= dfs_sheep;
		}
	}
	std::cout << sheep_cnt << " " << wolf_cnt;
}

int main()
{
	input();
	solve();
	return (0);
}
