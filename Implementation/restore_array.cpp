//16967
#include <iostream>
#define endl "\n"
int H, W, X, Y;
int g_map[600][600];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> H >> W >> X >> Y;
	for (int i = 0 ; i < H + X ; i++)
		for (int j = 0 ; j < W + Y ; j++)
			std::cin >> g_map[i][j];
}

void solve()
{
	for (int i = 0 ; i < H ; i++)
		for (int j = 0 ; j < W ; j++)
		{
			if (i >= X && j >= Y)
				g_map[i][j] -= g_map[i - X][j - Y];
		}
}

void print_val()
{
	for (int i = 0 ; i < H ; i++)
	{
		for (int j = 0 ; j < W ; j++)
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
