//9205
#include <iostream>
#include <cmath>
#define endl "\n"
#define MAX 999999999

int g_map[103][103];
int t, n;
std::pair<int, int> coord[103];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> t;
}

void floyd()
{
	for (int k = 0 ; k <= n + 1 ; k++)
		for (int i = 0 ; i <= n + 1 ; i++)
			for (int j = 0 ; j <= n + 1 ; j++)
				if (g_map[i][j] > g_map[i][k] + g_map[k][j])
					g_map[i][j] = g_map[i][k] + g_map[k][j];
}

void solve()
{
	int a, b;

	std::cin >> n >> coord[0].first>> coord[0].second;
	for (int i = 0 ; i < n;  i++)
	{
		std::cin >> a >> b;
		coord[i + 1].first = a;
		coord[i + 1].second = b;
	}
	std::cin >> coord[n + 1].first >> coord[n + 1].second ;

	int dist;

	for (int i = 0 ; i <= n + 1 ; i++)
	{
		for (int j = 0 ; j <= n + 1 ; j++)
		{
			if (coord[i].first == coord[j].first && coord[i].second == coord[j].second)
				continue;
			dist = std::abs(coord[i].first - coord[j].first) + std::abs(coord[i].second - coord[j].second);
			if (dist > 1000)
				g_map[i][j] = MAX;
			else
				g_map[i][j] = dist;
		}
	}
	floyd();
	if (g_map[0][n + 1] < MAX)
		std::cout << "happy" << endl;
	else
		std::cout << "sad" << endl;
}

int main()
{
	input();
	while (t--)	
		solve();

	return (0);
}
