//18111
#include <iostream>

int N, M, B;
int g_map[501][501];
int ans = 2000000000;
int min_height = 257, max_height = -1, ans_height;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> N >> M >> B;
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < M ; j++)
		{
			std::cin >> g_map[i][j];
			if (min_height > g_map[i][j])
				min_height = g_map[i][j];
			if (max_height < g_map[i][j])
				max_height = g_map[i][j];
		}
}

void brute(int y_index, int x_index, int val, int blocks, int height)
{
	if (y_index == N - 1 && x_index == M)
	{
		if (val <= ans && blocks >= 0)
		{
			ans = val;
			ans_height = height;
		}
		return ;
	}
	if (x_index == M)
	{
		y_index++;
		x_index = 0;
	}
	if (g_map[y_index][x_index] > height)
		brute(y_index, x_index + 1, val + (g_map[y_index][x_index] - height) * 2, blocks + g_map[y_index][x_index] - height, height);
	else if (g_map[y_index][x_index] == height)
		brute(y_index, x_index + 1, val, blocks, height);
	else
	{
		brute(y_index, x_index + 1, val + height - g_map[y_index][x_index], blocks - (height - g_map[y_index][x_index]), height);
	}
}

void solve()
{
	for (int i = min_height ; i <= max_height ; i++)
		brute(0, 0, 0, B, i);
}

void print_val()
{
	std::cout << ans << " " << ans_height;
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}
