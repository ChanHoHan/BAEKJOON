//1074
#include <iostream>
#include <cmath>

int N, r, c;
int cnt;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> N >> r >> c;
}

void dc(int y, int x, int len)
{
	if (y == r && x == c)
		return;
	if (y <= r && r < y + len/2 && x <= c && c < x + len / 2)
		dc(y, x, len / 2);
	else if (y <= r && r < y + len / 2 && x + len / 2 <= c && c < x + len)
	{
		cnt += (std::pow(len / 2, 2));
		dc(y, x + len / 2, len / 2);
	}
	else if (y + len / 2 <= r && r < y + len && x <= c && c < x + len / 2)
	{
		cnt += 2 * (std::pow(len / 2, 2));
		dc(y + len / 2, x , len / 2);
	}
	else
	{
		cnt += 3 * (std::pow(len / 2, 2));
		dc(y + len / 2, x + len / 2, len / 2);
	}
}

void solve()
{
	dc(0, 0, std::pow(2, N));
}

void print_val()
{
	std::cout << cnt;
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}
