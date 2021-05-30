//14502
#include <iostream>
#include <queue>
#include <cstring>

int N, M;
int g_map[9][9];
int cp_map[9][9];
std::queue<std::pair<int, int> >q;
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
int ans = 0;

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

void bfs()
{
	int qy, qx, ny, nx;
	
	std::memcpy(cp_map, g_map, sizeof(g_map));
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < M ; j++)
			if (g_map[i][j] == 2)
				q.push({i, j});
	while (!q.empty())
	{
		qy = q.front().first;
		qx = q.front().second;
		q.pop();
		for (int i = 0 ; i < 4 ; i++)
		{
			ny = qy + dy[i];
			nx = qx + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M || cp_map[ny][nx])
				continue;
			cp_map[ny][nx] = 2;
			q.push({ny,nx});
		}
	}
}

void safe_area_check()
{
	int cnt = 0;

	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < M ; j++)
			if (!cp_map[i][j])
				cnt++;
	if (ans < cnt)
		ans = cnt;
}

void brute_force(int ind, int cnt)
{
	int y, x;

	if (cnt == 3)
	{
		bfs();
		safe_area_check();
		return ;
	}
	if (ind >= N * M)
		return ;
	for (int i = ind ; i < N * M ; i++)
	{
		x = i % M;
		y = i / M;

		if (!g_map[y][x])
		{
			g_map[y][x] = 1;
			brute_force(i + 1, cnt + 1);
			g_map[y][x] = 0;
		}
	}
}

void solve()
{
	brute_force(0, 0);
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
