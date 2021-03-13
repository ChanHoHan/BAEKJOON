//3184
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

char g_map[251][251];
char visited[251][251];
std::vector<std::pair<int, int> >sheeps_loc;
std::queue<std::pair<int, int> >q;
int R, C, f_sheeps, f_wolves;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	std::string tmp;

	input_faster();
	std::cin >> R >> C;
	sheeps_loc.reserve(251);
	for (int i = 0 ; i < R ; i++)
	{
		std::cin >> tmp;
		for (size_t j = 0 ; j < tmp.size() ; j++)
		{
			g_map[i][j] = tmp[j];
			if (g_map[i][j] == 'o')
				sheeps_loc.push_back({i, j});
			else if (g_map[i][j] == 'v')
				f_wolves++;
		}
	}
}

void bfs(int y, int x)
{
	int q_x, q_y, n_y, n_x;
	int range_wolves = 0;
	int range_sheeps = 1;
	int range = 1;
	
	g_map[y][x] = 'k';
	q = std::queue<std::pair<int, int> >();
	q.push({y, x});
	while(!q.empty())
	{
		q_y = q.front().first;
		q_x = q.front().second;
		q.pop();
		for (int i = 0 ; i < 4; i++)
		{
			n_y = q_y + dy[i];
			n_x = q_x + dx[i];
			if (n_y < 0 || n_x < 0 || n_y >= R || n_x >= C)
			{
				range = 0;
				continue;
			}
			if (g_map[n_y][n_x] == '#' || visited[n_y][n_x])
				continue;
			if (g_map[n_y][n_x] == 'o')
			{
				range_sheeps++;
				g_map[n_y][n_x] = 'k';
			}
			else if (g_map[n_y][n_x] == 'v')
			{
				range_wolves++;
				g_map[n_y][n_x] = 'k';
			}
			visited[n_y][n_x] = 1;
			q.push({n_y, n_x});
		}
	}
	if (!range)
		f_sheeps += range_sheeps;
	else if (range_sheeps > range_wolves)
	{
		f_wolves -= range_wolves;
		f_sheeps += range_sheeps;
	}
}

void print_val()
{
	std::cout << f_sheeps << " " << f_wolves;
}

void solve()
{
	int y, x;
	for (size_t i = 0 ; i < sheeps_loc.size() ; i++)
	{
		y = sheeps_loc[i].first;
		x = sheeps_loc[i].second;
		if (g_map[y][x]!='k')
		{
			memset(visited, 0, sizeof(visited));
			bfs(y, x);
		}
	}	
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}

