//2580
#include <iostream>
#include <cstring>
#define endl "\n"
int g_map[10][10];
bool check[10];
void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	for(int i = 0 ; i < 9 ; i++)
		for (int j = 0 ; j < 9 ; j++)
			std::cin >> g_map[i][j];
}

bool row_check(int i)
{
	std::memset(check, 0, sizeof(check));
	for (int j = 0 ; j < 9 ; j++)
	{
		if (check[g_map[i][j]] and g_map[i][j])
			return (0);
		check[g_map[i][j]] = 1;
	}
	return (1);
}

bool col_check(int j)
{
	std::memset(check, 0, sizeof(check));
	for (int i = 0 ; i < 9 ; i++)
	{
		if (check[g_map[i][j]] and g_map[i][j])
			return (0);
		check[g_map[i][j]] = 1;
	}
	return (1);
}

bool square_check(int y, int x)
{
	std::memset(check, 0, sizeof(check));
	for (int i = y ; i < y + 3 ; i++)
		for (int j = x ; j < x + 3 ; j++)
		{
			if (check[g_map[i][j]] and g_map[i][j])
				return (0);
			check[g_map[i][j]] = 1;
		}
	return (1);
}

bool backtracking(int i, int j)
{
	if (i == 8 && j == 9)
		return (1);
	if (j == 9)
	{
		i++;
		j = 0;
	}
	if (g_map[i][j])
		return (backtracking(i, j+1));
	for (int k = 1 ; k < 10 ; k++)
	{
		g_map[i][j] = k;
		if (!row_check(i))
			continue;
		if (!col_check(j))
			continue;
		if (!square_check(i - i % 3 , j - j % 3))
			continue;
		if (backtracking(i, j + 1))
			return (1);
	}
	g_map[i][j] = 0;
	return(0);
}


void solve()
{
	backtracking(0, 0);
}

void print_val()
{
	for (int i = 0 ; i < 9 ; i++)
	{
		for (int j = 0 ; j < 9 ; j++)
			std::cout << g_map[i][j] << " ";
		std::cout << endl;
	}
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}

