//6987
#include <iostream>
#include <cstring>

int wordcup[4][18];
int tmp_map[7][7];
int ans[4];
int tmp[18];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	for (int i = 0 ; i < 4 ; i++)
		for (int j = 0 ; j < 18 ; j++)
			std::cin >> wordcup[i][j];
}

void check()
{
	int fl;

	for (int j = 0 ; j < 4 ; j++)
	{
		if (ans[j])
			continue;
		fl = 0;
		for (int i = 0 ; i < 18 ; i++)
		{
			if (tmp[i] != wordcup[j][i])
			{
				fl = 1;
				break;
			}
		}
		if (!fl)
			ans[j] = 1;
	}
}

void brute(int y, int x)
{
	if (y == 5 && x == 6)
	{
		check();
		return ;
	}
	if (x == 6)
	{
		for (int i = y + 1 ; i < 6 ; i++)
		{
			if (tmp_map[y][i] == 3)
				tmp[i * 3 + 2] += 1;
			else if (tmp_map[y][i] == 2)
				tmp[i * 3 + 1] += 1;
			else if (tmp_map[y][i] == 1)
				tmp[i * 3] += 1;
		}
		brute(y + 1, y + 2);
		for (int i = y + 1 ; i < 6 ; i++)
		{
			if (tmp_map[y][i] == 3)
				tmp[i * 3 + 2] -= 1;
			else if (tmp_map[y][i] == 2)
				tmp[i * 3 + 1] -= 1;
			else if (tmp_map[y][i] == 1)
				tmp[i * 3] -= 1;
		}
	}
	else
	{
		for (int j = 1 ; j <= 3; j++)
		{
			tmp_map[y][x] = j;
			if (j == 1)
				tmp[y * 3 + 2] += 1;
			else if (j == 2)
				tmp[y * 3 + 1] += 1;
			else if (j == 3)
				tmp[y * 3] += 1;
			brute(y, x + 1);
			if (j == 1)
				tmp[y * 3 + 2] -= 1;
			else if (j == 2)
				tmp[y * 3 + 1] -= 1;
			else if (j == 3)
				tmp[y * 3] -= 1;

		}
	}
}

void solve()
{
	brute(0, 1);
}

void print_val()
{
	for (int i = 0 ; i < 4 ; i++)
		std::cout<<ans[i] << " ";
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}
