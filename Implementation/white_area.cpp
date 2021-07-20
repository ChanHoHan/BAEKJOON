#include <iostream>

char g_map[9][9];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	for (int i = 0 ; i < 8 ; i++)
		std::cin >> g_map[i];
}

void solve()
{
	int ans = 0;

	for (int i = 0 ; i < 8 ; i++)
	{
		if (i % 2) // 홀수
		{
			for (int j = 1 ; j < 8 ; j+=2)
				if (g_map[i][j] == 'F')
					ans++;
		}
		else
		{
			for (int j = 0 ; j < 8 ; j+=2)
				if (g_map[i][j] == 'F')
					ans++;
		}
	}
	std::cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}
