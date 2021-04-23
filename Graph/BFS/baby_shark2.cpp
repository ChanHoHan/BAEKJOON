//17086
#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#include <algorithm>

int N, M;
int g_map[51][51];
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
		{
			std::cin >> g_map[i][j];
			if (g_map[i][j])
				q.push({i, j});
		}
}

void bfs()
{
	int qy, qx, nx, ny;

	while (!q.empty())
	{
		qy = q.front().first;
		qx = q.front().second;
		q.pop();
		for (int i = 0 ; i < 8 ; i++)
		{
			ny = qy + dy[i];
			nx = qx + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue ;
			if (!g_map[ny][nx])
			{
				q.push({ny, nx});
				g_map[ny][nx] = g_map[qy][qx] + 1;
				if (ans < g_map[qy][qx])
					ans = g_map[qy][qx];
			}
		}
	}
}

void solve()
{
	bfs();
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

