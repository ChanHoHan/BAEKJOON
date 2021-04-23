//17086
#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#include <algorithm>

int N, M;
int g_map[51][51];
int visited[51][51];
std::queue<std::pair<int, int> >q;
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int ans;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> N >> M;
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < M ; j++)
			std::cin >> g_map[i][j];
}

void bfs(int y, int x)
{
	int q_size, qy, qx, nx, ny, dist = 1;

	q = std::queue<std::pair<int, int> >();
	std::memset(visited, 0, sizeof(visited));
	visited[y][x] = 1;
	q.push({y, x});
	while (!q.empty())
	{
		q_size = q.size();
		for (int z = 0 ; z < q_size ; z++)
		{
			qy = q.front().first;
			qx = q.front().second;
			q.pop();
			for (int i = 0 ; i < 8 ; i++)
			{
				ny = qy + dy[i];
				nx = qx + dx[i];
				if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx])
					continue;
				if (g_map[ny][nx])
				{
					ans = std::max(ans, dist); 
					return ;
				}
				visited[ny][nx] = 1;
				q.push({ny, nx});
			}
		}
		dist++;
	}
}

void solve()
{
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < M ; j++)
			if (!g_map[i][j])
				bfs(i, j);
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

