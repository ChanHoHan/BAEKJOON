//15685
#include <iostream>
#include <stack>

int N;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
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
}

int change(int d)
{
	return (d + 1) % 4;
}

void solve()
{
	int x, y, d, g, val,ans = 0;

	while (N--)
	{
		std::cin >> x >> y >> d >> g;
		g_map[x][y] = 1;
		x += dx[d];
		y += dy[d];
		g_map[x][y] = 1;
		std::stack<int> s;
		std::stack<int> save;
		s.push(d);
		save.push(d);
		while (g--)
		{
			while (!s.empty())
			{
				val = s.top();
				s.pop();
				val = change(val);
				x += dx[val];
				y += dy[val];
				g_map[x][y] = 1;
				save.push(val);
			}
			s = save;
		}
	}

	for (int i = 0 ; i < 100 ; i++)
	{
		for (int j = 0 ; j < 100 ; j++)
		{
			if (g_map[i][j] && g_map[i + 1][j] && g_map[i][j + 1] && g_map[i + 1][j + 1])
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
