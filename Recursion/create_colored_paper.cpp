//2630
#include <iostream>
#define endl "\n"

int N;
bool g_map[129][129];
int answer[2];

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
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < N ; j++)
			std::cin >> g_map[i][j];
}

void divide_and_conquer(int y, int x, int length)
{
	bool color = g_map[y][x];
	bool flag = 1;
	for (int i = y ; flag && i < y + length ; i++)
		for (int j = x ; j < x + length ; j++)
			if (color != g_map[i][j])
			{
				divide_and_conquer(y, x, length / 2);
				divide_and_conquer(y, x + length / 2, length / 2);
				divide_and_conquer(y + length / 2, x, length / 2);
				divide_and_conquer(y + length / 2, x + length / 2, length / 2);
				flag = 0;
				break;
			}
	if (flag)
		answer[color]++;
}

void solve()
{
	divide_and_conquer(0, 0, N);
}

void print_val()
{
	std::cout << answer[0] << endl << answer[1];
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}

