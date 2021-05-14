//20057
#include <iostream>
#include <vector>

#define endl "\n"
int N, s_y, s_x;
int ans;
int g_map[501][501];
std::vector<std::vector<std::vector<std::pair<int, int> > > >cal = {{{{1, 0}, {-1, 0}}, {{1, 0}, {2, 0}, {-1, 0}, {-2, 0}}, {{1, 0}, {-1, 0}}, {{0, 0}}}, {{{0, -1}, {0, 1}}, {{0, -1}, {0, -2}, {0, 1}, {0, 2}}, {{0, 1}, {0, -1}}, {{0, 0}}}};
std::vector<std::vector<double> > val = {{0.01, 0.01}, {0.07, 0.02, 0.07, 0.02}, {0.1, 0.1}, {0.05}};
int dy[4] = {0, 1, 0, -1};
int dx[4] = {-1, 0, 1, 0};

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
	for (int i = 1 ; i <= N ; i++)
		for (int j = 1 ; j <= N ; j++)
			std::cin >> g_map[i][j];
	s_x = s_y = (N/2 + 1);
}

void tornado(int d)
{
	int ny, nx, _dy, _dx, _nx, _ny, cumul = 0, sand = 0, tmp;
	if (s_y + dy[d] > 0 && s_y + dy[d] <= N && s_x + dx[d] > 0 && s_x + dx[d] <= N)
		sand = g_map[s_y + dy[d]][s_x + dx[d]];
	ny = s_y;
	nx = s_x;
	for (int i = 0 ; i < 4; i++)
	{
		for (size_t j = 0 ; j < cal[d % 2][i].size() ; j++)
		{
			_dy = cal[d%2][i][j].first;
			_dx = cal[d%2][i][j].second;
			_ny = _dy + ny;
			_nx = _dx + nx;
			if (_ny <= 0 || _ny > N || _nx <= 0 || _nx > N)
			{
				ans+=(int)(sand * val[i][j]);
				cumul += (int)(sand * val[i][j]);
				continue;
			}
			tmp = (int)(sand * val[i][j]);
			g_map[_ny][_nx] += tmp;
			cumul += tmp;
		}
		ny += dy[d];
		nx += dx[d];
	}
	int alpha_y = s_y + dy[d] * 2, alpha_x = s_x + dx[d] * 2;
	if (alpha_y > 0 && alpha_y <= N && alpha_x > 0 && alpha_x <= N)
		g_map[alpha_y][alpha_x] += (sand - cumul);
	else
		ans += (sand - cumul);
	ny = s_y + dy[d];
	nx = s_x + dx[d];
	g_map[ny][nx] = g_map[s_y][s_x];
	g_map[s_y][s_x] = 0;
}

void solve()
{
	int i = 1;
	int cnt;
	int d = 0;
	while(!(s_y == 1 && s_x == 1))
	{
		for (int j = 0 ; j < 2 ; j++)
		{
			cnt = i;
			while (cnt--)
			{
				tornado(d);
				s_y += dy[d];
				s_x += dx[d];
				if (s_y == 1 && s_x == 1)
					break;
			}
			if (s_y == 1 && s_x == 1)
				break;
			d = (d + 1) % 4;
		}
		i++;
	}
	return ;
}

void print_val()
{
	std::cout << ans;
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}

