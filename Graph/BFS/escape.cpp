#include <iostream>
#include <queue>
#define FAIL "KAKTUS"

int R,C;
char g_map[51][51];
int g_map_cnt[51][51];
std::queue<std::pair<std::pair<int, int>,char>  >q;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
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
	std::cin >> R >> C;
	for (int i = 0 ; i < R ; i++)
		for (int j = 0 ; j < C ; j++)
		{
			std::cin >> g_map[i][j];
			if (g_map[i][j] == '*' || g_map[i][j] == 'S')
				q.push({{i, j}, g_map[i][j]});
		}
}

bool bfs()
{
	int qy, qx, ny, nx;
	char val;

	while(!q.empty())
	{
		qy = q.front().first.first;
		qx = q.front().first.second;
		val = q.front().second;
		q.pop();
		if (val == 'S' && val != g_map[qy][qx])
			continue;
		for (int i = 0 ; i < 4 ; i++)
		{
			ny = qy + dy[i];
			nx = qx + dx[i];
			if (nx < 0 || nx >= C || ny < 0 || ny >= R || g_map[ny][nx] == 'X')
				continue;
			if (g_map[ny][nx] == 'D' && g_map[qy][qx] == 'S')
			{
				ans = g_map_cnt[qy][qx] + 1;
				return (1);
			}
			if (g_map[qy][qx] == '*' && g_map[ny][nx] == 'S' && g_map_cnt[ny][nx] <= g_map_cnt[qy][qx])
				continue;
			if (g_map[ny][nx] == 'D' || g_map[ny][nx] == g_map[qy][qx] || g_map[ny][nx] == '*')
				continue;
			g_map[ny][nx] = g_map[qy][qx];
			g_map_cnt[ny][nx] = g_map_cnt[qy][qx] + 1;
			q.push({{ny,nx}, val});
		}
	}
	return (0);
}

void solve()
{
	if(bfs())
		std::cout << ans;
	else
		std::cout << FAIL;
}

int main()
{
	input();
	solve();
	return (0);
}

