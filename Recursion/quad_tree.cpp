//1992
#include <iostream>

int N;
char g_map[65][65];
std::string ans;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	std::string tmp;
	io_faster();
	std::cin >> N;
	for (int i = 0 ; i < N ; i++)
		std::cin >> g_map[i];
	ans = "";
}

void divide_and_conquer(int y, int x, int length)
{
	char color = g_map[y][x];
	int flag = 0;

	for (int i = y ; !flag && i < y + length ; i++)
		for (int j = x ; j < x + length ; j++)
			if (color != g_map[i][j])
			{
				flag = 1;
				break;
			}
	if (flag)
	{
		ans += "(";
		divide_and_conquer(y, x, length / 2);
		divide_and_conquer(y, x + length / 2, length / 2);
		divide_and_conquer(y + length / 2, x, length / 2);
		divide_and_conquer(y + length / 2, x + length / 2, length / 2);
		ans += ")";
	}
	else
		ans += color;
}

void solve()
{
	divide_and_conquer(0, 0, N);
}

void print_val()
{
	std::cout << ans;
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}

