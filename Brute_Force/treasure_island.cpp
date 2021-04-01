//2589
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

int N, M;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int g_map[51][51];
bool visited[51][51];
int ans_map[51][51];

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
	std::string tmp;
	for (int i = 0 ; i < N ; i++)
	{
		std::cin >> tmp;
		for (int j = 0 ; j < M ; j++)
			g_map[i][j] = tmp[j];
	}
}

void bfs(int y, int x)
{
	int qy, qx, ny, nx;
	visited[y][x] = 1;
	q.push({y, x});
	ans_map[y][x] = 0;

	while(!q.empty())
	{
		qy = q.front().first;
		qx = q.front().second;
		q.pop();
		for (int i = 0 ; i < 4 ; i++)
		{
			nx = qx + dx[i];
			ny = qy + dy[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || g_map[ny][nx] == 'W')
				continue;
			visited[ny][nx] = 1;
			ans_map[ny][nx] = ans_map[qy][qx] + 1;
			ans = std::max(ans_map[ny][nx], ans);
			q.push({ny, nx});
		}
	}
}

void solve()
{
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < M ; j++)
			if (g_map[i][j] == 'L')
			{
				std::memset(visited, 0, sizeof(visited));
				std::memset(ans_map, 0, sizeof(ans_map));
				bfs(i, j);
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

