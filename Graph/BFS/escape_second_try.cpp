#include <iostream>
#include <queue>

char g_map[51][51];
int R, C;
std::queue<std::pair<int, int> >water;
std::queue<std::pair<int, int> >hedgehog;
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

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
		std::cin >> g_map[i];
}

void make_queue()
{
	for (int i = 0 ; i < R ; i++)
		for (int j = 0 ; j < C ; j++)
		{
			if (g_map[i][j] == 'S')
				hedgehog.push({i, j});
			else if (g_map[i][j] == '*')
				water.push({i, j});
		}
}

void water_bfs()
{
	int qy, qx, ny, nx;

	std::queue<std::pair<int, int> >temp;
	while (!water.empty())
	{
		qy = water.front().first;
		qx = water.front().second;
		water.pop();
		for (int i = 0 ; i < 4 ; i++)
		{
			ny = qy + dy[i];
			nx = qx + dx[i];
			if (ny < 0 || ny >= R || nx < 0 || nx >= C || g_map[ny][nx] == 'D' || g_map[ny][nx] == 'X' || g_map[ny][nx] == '*')
				continue;
			g_map[ny][nx] = '*';
			temp.push({ny, nx});
		}
	}
	water = temp;
}

bool hedgehog_bfs()
{
	int qy, qx, ny, nx;

	std::queue<std::pair<int, int> >temp;
	while (!hedgehog.empty())
	{
		qy = hedgehog.front().first;
		qx = hedgehog.front().second;
		hedgehog.pop();
		for (int i = 0 ; i < 4 ; i++)
		{
			ny = qy + dy[i];
			nx = qx + dx[i];
			if (ny < 0 || ny >= R || nx < 0 || nx >= C || g_map[ny][nx] == '*' || g_map[ny][nx] == 'X' || g_map[ny][nx] == 'S')
				continue;
			if (g_map[ny][nx] == 'D')
				return (1);
			g_map[ny][nx] = 'S';
			temp.push({ny, nx});
		}
	}
	hedgehog = temp;
	return (0);
}

void solve()
{
	int i = 0;

	make_queue();
	while (++i < 2500)
	{
		water_bfs();
		if(hedgehog_bfs())
		{
			std::cout << i;
			return ;
		}
	}
	std::cout << "KAKTUS";
}

int main()
{
	input();
	solve();
	return (0);
}
