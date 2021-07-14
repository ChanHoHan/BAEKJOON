//11404
#include <iostream>
#include <cstring>
#define endl "\n"

int n, m, g_map[102][102];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	int a, b, cost;

	io_faster();
	std::cin >> n >> m;
	std::memset(g_map, 0x3f, sizeof(g_map));
	for (int i = 0 ; i < m ; i++)
	{
		std::cin >> a >> b >> cost;
		if (g_map[a][b] > cost)
			g_map[a][b] = cost;
	}
	for (int i = 1 ; i <= n ; i++)
		g_map[i][i] = 0;
}

void solve()
{
	for (int i = 1 ; i <= n ; i++)
		for (int j = 1 ; j <= n ; j++)
			for (int z = 1 ; z <= n ; z++)
				if (g_map[j][z] > g_map[j][i] + g_map[i][z])
					g_map[j][z] = g_map[j][i] + g_map[i][z];
	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 1 ; j <= n ; j++)
		{
			if (g_map[i][j] < g_map[101][101])
				std::cout << g_map[i][j];
			else
				std::cout << 0;
			std::cout << " ";
		}
		std::cout << endl;
	}
}

int main()
{
	input();
	solve();
	return (0);
}
