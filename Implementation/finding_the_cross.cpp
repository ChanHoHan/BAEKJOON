//16924
#include <iostream>
#include <vector>
#define endl "\n"

int N, M;
char g_map[101][101];
bool cross_check[101][101];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
std::vector<std::pair<std::pair<int, int>, int> > cross;
int ans;

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void the_cross(int y, int x, int length)
{
	int ny, nx;

	for (int i = 0 ; i < 4 ; ++i)
	{
		ny = y + length * dy[i];
		nx = x + length * dx[i];
		if (ny <= 0 || ny > N || nx <= 0 || nx > M || g_map[ny][nx] != '*' || g_map[ny][nx] != '*')
			return ;
	}
	for (int i = 0 ; i < 4 ; ++i)
	{
		ny = y + length * dy[i];
		nx = x + length * dx[i];
		cross_check[ny][nx] = 1;
	}
	cross_check[y][x] = 1;
	cross.push_back({{y, x}, length});
	the_cross(y, x, length + 1);
}

void input()
{
	input_faster();
	std::cin >> N >> M;
	for (int i = 1 ; i <= N ; ++i)
		for (int j = 1 ; j <= M ; ++j)
			std::cin >> g_map[i][j];
}

void make_the_cross()
{
	for (int i = 1 ; i <= N ; ++i)
		for (int j = 1 ; j <= M ; ++j)
			if (g_map[i][j] == '*')
				the_cross(i, j, 1);	
}

void solve()
{
	make_the_cross();
}

void print_val()
{
	for (int i = 1 ; i <= N ; ++i)
		for (int j = 1; j <= M; ++j)
		{
			if (!cross.size() || (g_map[i][j] == '*' && !cross_check[i][j]))
			{
				std::cout << -1;
				return ;
			}
		}

	std::cout << cross.size() << endl;
	for (auto& i : cross)
		std::cout << i.first.first << " " << i.first.second << " " << i.second << endl;
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}
