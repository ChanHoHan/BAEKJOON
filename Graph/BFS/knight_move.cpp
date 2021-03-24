//7562
#include <iostream>
#include <string.h>
#include <queue>
#include <tuple>

#define endl "\n"

int T, l;
int k_y, k_x;//knight y x
int f_y, f_x;//final y x
int chess[301][301];
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
std::queue<std::tuple<int, int, int> > q;

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> T;
}

void solve()
{
	int x,y, m_x, m_y, dist;
	std::cin >> l >> k_y >> k_x >> f_y >> f_x;
	
	q.push({k_y, k_x, 0});
	chess[k_y][k_x] = 1;
	while(!q.empty())
	{
		y = std::get<0>(q.front());
		x = std::get<1>(q.front());
		dist = std::get<2>(q.front());
		q.pop();
		if (y == f_y && x == f_x)
		{
			std::cout << dist << endl;
			return ;
		}
		for (int i = 0 ; i < 8 ; i++)
		{
			m_y = y + dy[i];
			m_x = x + dx[i];
			if (m_y < 0 || m_y >= l || m_x < 0 || m_x >= l || chess[m_y][m_x])
				continue;
			chess[m_y][m_x] = 1;
			q.push({m_y , m_x, dist + 1});
		}
	}
}

int main()
{
	input();
	while (T--)
	{
		memset(chess, 0, sizeof(chess));
		q = std::queue<std::tuple<int, int, int> >();
		solve();
	}
	return (0);
}
