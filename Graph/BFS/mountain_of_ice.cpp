//2573
#include <iostream>
#include <cstring>
#include <queue>

#define endl "\n"

int N, M;
int g_map[302][302];
int tmp[302][302];
bool visited[302][302];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
std::queue<std::pair<int, int> >q;
int ans;

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> N >> M;
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < M ; j++)
			std::cin >> g_map[i][j];
}

void bfs(int i, int j)
{
	int y,x, nx,ny;
	visited[i][j] = 1;
	q.push({i, j});
	while(!q.empty())
	{
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int k = 0 ; k < 4 ; k++)
		{
			ny = y + dy[k];
			nx = x + dx[k];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || !g_map[ny][nx])
				continue;
			visited[ny][nx] = 1;
			q.push({ny, nx});
		}
	}
}

int cal_ice()
{
	int ret = 0;

	q = std::queue<std::pair<int, int> >();
	memset(visited, 0, sizeof(visited));
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < M ; j++)
		{
			if (visited[i][j] || !g_map[i][j])
				continue;
			ret++;
			bfs(i, j);
		}
	return (ret);
}

int cal_surround_water(int y, int x)
{
	int nx, ny;
	int ret = 0;

	for (int k = 0 ; k < 4 ; k++)
	{
		ny = y + dy[k];
		nx = x + dx[k];
		if (ny < 0 || ny >= N || nx < 0 || nx >= M || g_map[ny][nx])
			continue;
		ret++;
	}
	return (ret);
}

bool no_ice()
{
	for (int i = 0 ;i < N ; i++)
		for (int j = 0 ; j < M ; j++)
			if (g_map[i][j])
				return (0);
	ans = 0;
	return (1);
}

void solve()
{
	int surrounded_water;

	while(cal_ice() < 2 && !no_ice())
	{
		for (int i = 0 ; i < N ; i++)
			for (int j = 0 ; j < M ; j++)
			{
				if (!g_map[i][j])
				{
					tmp[i][j] = 0;
					continue;
				}
				surrounded_water = cal_surround_water(i, j);
				tmp[i][j] = g_map[i][j] - surrounded_water;
				if (tmp[i][j] < 0)
					tmp[i][j] = 0;
			}
		std::memcpy(g_map, tmp, sizeof(tmp));
		ans++;
	}
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

