//1780
#include <iostream>

int N;
int ans[3] = {0, 0, 0};
int g_map[2200][2200];

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

bool is_all_same(int y1, int x1, int y2, int x2)
{
	int val = g_map[y1][x1];

	for (int i = y1 ; i < y2 ; i++)
		for (int j = x1 ; j < x2 ; j++)
			if (val != g_map[i][j])
				return (0);
	return (1);	
}

void input()
{
	input_faster();
	std::cin >> N;
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < N ; j++)
			std::cin >> g_map[i][j];
}

void divide_and_conquer(int y1, int x1, int y2, int x2)
{
	int interval, dy, dx;

	if (!is_all_same(y1, x1, y2, x2))
	{
		interval = (y2 - y1) / 3;
		dy = 0;
		for (int i = 0 ; i < 3; i++)
		{
			dy = i * interval;
			dx = 0;
			for (int j = 0 ; j < 3 ; j++)
			{
				dx = j * interval;
				divide_and_conquer(y1 + dy, x1 + dx, y1 + dy + interval, x1 + dx + interval);
			}
		}
	}
	else
	{
		if (g_map[y1][x1] == -1)
			ans[0]+=1;
		else if (g_map[y1][x1] == 0)
			ans[1]+=1;
		else if (g_map[y1][x1] == 1)
			ans[2]+=1;
	}
}

void solve()
{
	divide_and_conquer(0, 0, N, N);
}

void print_val()
{
	for (int i = 0 ; i < 3 ; i++)
		std::cout << ans[i] << " ";
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}

