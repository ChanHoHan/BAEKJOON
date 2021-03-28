//14502
#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>

int N, M;
int g_map[10][10];
int g_map_cpy[10][10];
int visited[10][10];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
std::pair<int, int>pollution[11]; //pollution coord
std::queue<std::pair<int, int> >q;
int pollution_N;
int ans;

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	pollution_N = 0;

	input_faster();
	std::cin >> N >> M;
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < M ; j++)
		{
			std::cin >> g_map[i][j];
			if (g_map[i][j] == 2) // append pollution coordinates
			{
				pollution[pollution_N].first = i;
				pollution[pollution_N++].second = j;
			}
		}
	ans = 0;
}

void bfs(int y, int x) // bfs to make area being polluted
{
	int q_x, q_y, n_x, n_y;

	if(visited[y][x])
		return ;
	q.push({y,x});
	visited[y][x] = 1;
	while (!q.empty())
	{
		q_y = q.front().first;
		q_x = q.front().second;
		q.pop();
		for (int i = 0 ; i < 4 ; i++)
		{
			n_y = q_y + dy[i];
			n_x = q_x + dx[i];
			if (n_y < 0 || n_y >= N || n_x < 0 || n_x >= M || visited[n_y][n_x] || g_map_cpy[n_y][n_x] == 1)
				continue;
			visited[n_y][n_x] = 1;
			g_map_cpy[n_y][n_x] = 2;
			q.push({n_y, n_x});
		}
	}
}

void cal_not_pollution() // calculating where not polluted
{
	int cnt = 0;

	for (int i = 0 ; i < N ; i++)
	{
		for (int j = 0 ; j < M ; j++)
		{
			if (g_map_cpy[i][j] == 0)
				cnt++;
		}
	}
	ans = std::max(ans, cnt);
}

void backtracking(int y, int x, int cnt)
{
	for(int i = y ; i < N ; i++)
	{
		for (int j = x; j < M ; j++)
		{
			if (g_map[i][j] == 0 && cnt == 2) // if g_map[i][j] == 0 and determined 3 walls to calculate
			{
				memset(visited, 0, sizeof(visited));
				g_map[i][j] = 1;
				memcpy(g_map_cpy, g_map, sizeof(g_map));
				for (int k = 0; k < pollution_N ; k++)
					bfs(pollution[k].first, pollution[k].second);
				cal_not_pollution();
				g_map[i][j] = 0;

			}
			else if (g_map[i][j] == 0)
			{
				g_map[i][j] = 1;
				backtracking(i, j + 1, cnt + 1);
				g_map[i][j] = 0;
			}
		}
		x = 0; // x has to change to zero because of brute force
	}
}

void print_val()
{
	std::cout << ans;
}

void solve()
{
	backtracking(0, 0, 0);
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}

