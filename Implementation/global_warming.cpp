//5212
#include <iostream>
#include <algorithm>
#define endl "\n"

int R, C;
char g_map[11][11];
char new_map[11][11];
int dy[4][3] = {{0, -1, 0}, {-1, 0, 1}, {0, 1, 0}, {-1, 0, 1}};
int dx[4][3] = {{-1, 0, 1}, {0, 1, 0}, {-1, 0, 1}, {0, -1, 0}};

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
		std::cin >>  g_map[i];
}

bool check(int i, int j)
{
	int nx, ny,  cnt;

	for (int x = 0 ; x < 4 ; x++)
	{
		cnt = 0;
		for (int y = 0 ; y < 3 ; y++)
		{
			ny = i + dy[x][y];
			nx = j + dx[x][y];
			if (ny < 0 || ny >= R || nx < 0 || nx >= C || g_map[ny][nx] == '.')
				cnt++;
		}
		if (cnt == 3)
			return (1);
	}
	return (0);
}

void solve()
{
	int n_R1 = 30, n_R2 = -1, n_C1 = 30, n_C2 = -1;

	for (int i = 0 ; i < R ; i++)
		for (int j = 0 ; j < C ; j++)
		{
			if (g_map[i][j] == 'X' && check(i, j))
				new_map[i][j] = '.';
			else
				new_map[i][j] = g_map[i][j];
		}

	for (int i = 0 ; i < R ; i++)
		for (int j = 0 ; j < C ; j++)
		{
			if (new_map[i][j] == 'X')
			{
				n_R1 = std::min(n_R1, i);
				n_R2 = std::max(n_R2, i);
				n_C1 = std::min(n_C1, j);
				n_C2 = std::max(n_C2, j);
			}
		}
	for (int i = n_R1 ; i <= n_R2 ; i++)
	{
		for (int j = n_C1; j <= n_C2 ; j++)
			std::cout << new_map[i][j];
		std::cout << endl;
	}

}

int main()
{
	input();
	solve();
	return (0);
}
