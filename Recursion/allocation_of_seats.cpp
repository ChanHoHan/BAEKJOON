//10157
#include <iostream>
#include <cmath>

int C, R, K;
int col, row;
int ans_y, ans_x;

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> C >> R;
	std::cin >> K;
}

void recursion(int x, int y, int val, bool dir)
{
	if (col == 0 && row == 0)
		return ;
	if (!dir) // move row
	{
		y += row;
		val += std::abs(row);
	}
	else
	{
		x += col;
		val += std::abs(col);
	}
	if (val >= K)
	{
		if (!dir)
		{
			if (row > 0)
				y -= (val - K);
			else
				y += (val - K);
		}
		else
		{
			if (col > 0)
				x -= (val - K);
			else
				x += (val - K);
		}
		ans_y = y;
		ans_x = x;
		return ;
	}
	if (!dir && row < 0)
		row = -row - 1;
	else if (!dir && row > 0)
		row = -row + 1;
	else if (dir && col < 0)
		col = -col - 1;
	else if (dir && col > 0)
		col = -col + 1;
	recursion(x, y, val, !dir);
}

void solve()
{
	row = R;
	col = C - 1;
	recursion(1, 0, 0, 0);
}

void print_val()
{
	std::cout << ans_x << " " << ans_y;
}

int main()
{
	input();
	if (K > R * C)
	{
		std::cout << 0;
		return (0);
	}
	solve();
	print_val();
	return (0);
}

