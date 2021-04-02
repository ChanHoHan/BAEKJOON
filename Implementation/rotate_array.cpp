//16926
#include <iostream>
#define endl "\n"

int N, M, R;
int g_map[301][301];

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> N >> M >> R;
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < M ; j++)
			std::cin >> g_map[i][j];
}

void rotate_operation(int s_y, int s_x, int e_y, int e_x)
{
	int tmp, tmp2;

	tmp2 = g_map[s_y][s_x];
	for (int i = s_y ; i < e_y ; i++)
	{
		tmp = g_map[i + 1][s_x];
		g_map[i + 1][s_x] = tmp2;
		tmp2 = tmp;
	}
	for (int j = s_x ; j < e_x ; j++)
	{
		tmp = g_map[e_y][j + 1];
		g_map[e_y][j + 1] = tmp2;
		tmp2 = tmp;
	}
	for (int i = e_y ; i > s_y ; i--)
	{
		tmp = g_map[i - 1][e_x];
		g_map[i - 1][e_x] = tmp2;
		tmp2 = tmp;
	}
	for (int j = e_x ; j > s_x ; j--)
	{
		tmp = g_map[s_y][j - 1];
		g_map[s_y][j - 1] = tmp2;
		tmp2 = tmp;
	}
}

void solve()
{
	int start_x, start_y, end_x, end_y;

	while(R--)
	{
		start_x = 0;
		start_y = 0;
		end_x = M - 1;
		end_y = N - 1;

		while (start_x < end_x && start_y < end_y)
		{
			rotate_operation(start_y, start_x, end_y, end_x);
			start_x++;
			start_y++;
			end_x--;
			end_y--;
		}
	}
}

void print_val()
{
	for (int i = 0 ; i < N ; i++)
	{
		for (int j = 0 ; j < M ; j++)
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

