//2580
#include <iostream>
#define endl "\n"

int g_map[10][10];
int end = 81;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	for (int i = 0 ; i < 9 ; i++)
		for (int j = 0 ; j < 9 ; j++)
			std::cin >> g_map[i][j];
}

bool check(int r, int c, int val)
{
	for (int i = 0 ; i < 9 ; i++)
	{
		if (g_map[r][i] == val || g_map[i][c] == val)
			return (0);
	}
	// square
	int start_r = 3 * (r / 3);
	int start_c = 3 * (c / 3);
	bool check[10] = {0,};
	g_map[r][c] = val;
	for (int i = start_r ; i < start_r + 3 ; i++)
		for (int j = start_c ; j < start_c + 3 ; j++)
		{
			if (g_map[i][j] && check[g_map[i][j]])
			{
				g_map[r][c] = 0;
				return (0);
			}
			check[g_map[i][j]] = 1;
		}
	g_map[r][c] = 0;
	return (1);
}

bool backtracking(int index)
{
	int r = index / 9;
	int c = index % 9;


	if (index == end)
	{
		for (int i = 0 ; i < 9 ; i++)
		{
			for (int j = 0 ; j < 9 ; j++)
				std::cout << g_map[i][j] << " " ;
			std::cout << endl;
		}
		return (1);
	}
	if (g_map[r][c])
		return (backtracking(index + 1));
	for (int i = 1 ; i <= 9 ; i++)
	{
		if (!check(r, c, i))
			continue;
		g_map[r][c] = i;
		if(backtracking(index + 1))
			return (1);
		g_map[r][c] = 0;
	}
	return (0);
}

void solve()
{
	backtracking(0);
}

int main()
{
	input();
	solve();
	return (0);
}
