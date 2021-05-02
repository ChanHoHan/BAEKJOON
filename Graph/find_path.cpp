//11403
#include <iostream>
#define endl "\n"
int N;
bool g_map[101][101];

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

void make_floyd()
{
	for (int k = 0 ; k < N ; k++)
		for (int i = 0 ; i < N ; i++)
			for (int j = 0 ; j < N ; j++)
				if (g_map[i][k] && g_map[k][j])
					g_map[i][j] = 1;
}

void solve()
{
	make_floyd();
}

void print_val()
{
	for (int i = 0 ; i < N ; i++)
	{
		for (int j = 0 ; j < N ; j++)
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

