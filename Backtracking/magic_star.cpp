//3967
#include <iostream>
#include <vector>
#define endl "\n"

int g_map[6][10];
bool alphabet_table[13];
int coord_set[6][4][2] = {{{0, 4}, {1, 3}, {2, 2}, {3, 1}}, {{3, 1}, {3, 3}, {3, 5}, {3, 7}}, {{3, 7}, {2, 6}, {1, 5}, {0, 4}}, {{1, 1}, {2, 2}, {3, 3}, {4, 4}}, {{4, 4}, {3, 5}, {2, 6}, {1, 7}}, {{1, 7}, {1, 5}, {1, 3}, {1, 1}}};
std::vector<std::pair<int, int> >coord;

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::string tmp;

	for (int i = 0; i < 5 ; i++)
	{
		std::cin >> tmp;
		for (int j = 0 ; j < tmp.size(); j++)
		{
			if (tmp[j] == '.')
			{
				g_map[i][j] = 20;
				continue;
			}
			if ('A' <= tmp[j] && tmp[j] <= 'L')
			{
				g_map[i][j] = tmp[j] - 'A' + 1;
				alphabet_table[g_map[i][j]] = 1;
			}
			else
				g_map[i][j] = 0;
			coord.push_back({i, j});
		}
	}
}

bool is_lastpart(int y, int x)
{
	return ((y == 1 && x == 7) ||
			(y == 3 && x == 1) ||
			(y == 3 && x == 7) ||
			(y == 4 && x == 4));
}

bool sum(int ind)
{
	int cnt = 0;

	for (int i = 0 ; i < 4 ; i++)
		cnt += g_map[coord_set[ind][i][0]][coord_set[ind][i][1]];
	if (cnt == 26)
		return (1);
	return (0);
}

bool check(int y, int x)
{
	if (y == 1 && x == 7)
	{
		if (!sum(5)) // if not 26
			return (0);
	}
	else if (y == 3 && x == 1)
	{
		if (!sum(0))
			return (0);
	}
	else if (y == 3 && x == 7)
	{
		if (!sum(1) || !sum(2))
			return (0);
	}
	else if (y == 4 && x == 4)
	{
		if (!sum(3) || !sum(4))
			return (0);
	}
	return (1);
}

bool backtracking(int ind)
{
	if (ind == coord.size())
		return (1);
	int y = coord[ind].first;
	int x = coord[ind].second;

	if (g_map[y][x])
	{
		if (is_lastpart(y, x) && !check(y, x))
			return (false);
		if(backtracking(ind + 1))
			return (true);
		else
			return (false);
	}
	for (int i = 1 ; i <= 12 ; i++)
	{
		if (!alphabet_table[i])
		{
			g_map[y][x] = i;
			if (is_lastpart(y, x) && !check(y, x))
			{
				g_map[y][x] = 0;
				continue;
			}
			//after checking
			alphabet_table[i] = 1;
			if (backtracking(ind + 1))
				return (true);
			alphabet_table[i] = 0;
			g_map[y][x] = 0;
		}
	}
	return (false);
}

void solve()
{
	backtracking(0);
}

void print_val()
{
	char tmp;

	for (int i = 0 ; i < 5 ; i++)
	{
		for (int j = 0; j < 9 ; j++)
		{
			if (g_map[i][j] == 20)
				std::cout << '.';
			else
			{
				tmp = (char)g_map[i][j] + 'A' - 1;
				std::cout << tmp;
			}

		}
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

