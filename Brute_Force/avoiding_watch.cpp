//18428
#include <iostream>

int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
int N;
char g_map[7][7];
std::pair<int, int> teacher[7];
int teacher_size;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> N;
	for (int i = 1 ; i <= N ; i++)
		for (int j = 1 ; j <= N ; j++)
		{
			std::cin >> g_map[i][j];
			if (g_map[i][j] == 'T')
				teacher[teacher_size++] = {i, j};
		}
}

bool check()
{
	int y, x, ny, nx;

	for (int i = 0 ; i < teacher_size ; i++)
	{
		y = teacher[i].first;
		x = teacher[i].second;
		for (int j = 0 ; j < 4 ; j++)
		{
			ny = y;
			nx = x;
			while (ny >= 1 && ny <= N && nx >= 1 && nx <= N && g_map[ny][nx] != 'O')
			{
				if (g_map[ny][nx] == 'S')
					return (0);
				ny += dy[j];
				nx += dx[j];
			}
		}
	}
	return (1);
}

bool brute_force(int depth, int y, int x)
{
	if (depth == 3)
	{
		if(check())
			return (1);
		return (0);
	}
	if (y == N + 1)
		return (0);
	for (int i = y ; i <= N ; i++)
	{
		for (int j = 0 ; j <= N ; j++)
		{
			if (i == y && j < x)
				continue;
			if (g_map[i][j] == 'X')
			{
				g_map[i][j] = 'O';
				if (j == N ? brute_force(depth + 1, i + 1, 0) : brute_force(depth + 1, i, j + 1))
					return (1);
				g_map[i][j] = 'X';
			}
		}
	}
	return (0);
}

void solve()
{
	if(brute_force(0, 1, 1))
		std::cout << "YES";
	else
		std::cout << "NO";
}

int main()
{
	input();
	solve();
	return (0);
}
