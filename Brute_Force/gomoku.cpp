//2615
#include <iostream>
#include <algorithm>
#define endl "\n"
int g_map[19][19];
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
std::pair<int, int> save[5];

int ans_y, ans_x, black_white;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	for (int i = 0 ; i < 19 ; i++)
		for (int j = 0 ; j < 19 ; j++)
			std::cin >> g_map[i][j];
}

bool comp(std::pair<int,int>a, std::pair<int,int>b)
{
	return (a.first < b.first);
}

bool comp2(std::pair<int,int>a, std::pair<int,int>b)
{
	return (a.second < b.second);
}


bool dfs(int y, int x, int val, int depth, int dir_y, int dir_x, int dir)
{
	int ny, nx;

	ny = y + dir_y;
	nx = x + dir_x;
	if (depth == 5)
	{
		if (0 <= ny && ny < 19 && 0 <= nx && nx < 19 && g_map[ny][nx] == val)
			return (0);
		dir = (dir + 4) % 8;
		ny = y + 5 * dy[dir];
		nx = x + 5 * dx[dir];
		if (0 <= ny && ny < 19 && 0 <= nx && nx < 19 && g_map[ny][nx] == val)
			return (0);

		if (save[0].second == save[1].second)
			std::sort(save, save + 5, comp);
		else
			std::sort(save, save + 5, comp2);
		ans_y = save[0].first;
		ans_x = save[0].second;
		black_white = val;
		return (1);
	}
	if (ny < 0 || ny >= 19 || nx < 0 || nx >= 19 || val != g_map[ny][nx])
		return (0);
	save[depth].first = ny;
	save[depth].second = nx;
	return(dfs(ny, nx, val, depth + 1, dir_y, dir_x, dir));
}

void solve()
{
	int fl = 1;

	for (int i = 0 ; fl && i < 19 ; i++)
		for (int j = 0 ; fl && j < 19 ; j++)
		{
			save[0].first = i;
			save[0].second = j;
			if (g_map[i][j])
			{
				for (int k = 0 ; k < 8 ; k++)
				{
					if (dfs(i, j, g_map[i][j], 1, dy[k], dx[k], k))
					{
						fl = 0;
						break;
					}
				}
			}
		}
	if (fl)
		black_white = 0;
}

void print_val()
{
	std::cout << black_white << endl;
	if (black_white)
		std::cout << ans_y + 1 << " " << ans_x + 1;
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}
