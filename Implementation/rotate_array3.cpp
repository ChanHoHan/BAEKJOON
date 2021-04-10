//16935
#include <iostream>
#include <algorithm>
#include <cstring>
#define endl "\n"
#define FOR(i, n) for(int i = 0 ; i < n ; i++)
#define D_FOR(i, n) for(int i = n ; i >= 0 ; i--)
#define R_FOR(i, s, n) for (int i = s ; i < n ; i++)

int N, M, R, OP;
int g_map[101][101];
int tmp[101][101];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

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
	FOR(i, N)
	FOR(j, M) std::cin >> g_map[i][j];
}

void rotate()
{
	if (OP == 1)
	{
		FOR(i, N)
		FOR(j, M) tmp[N - i - 1][j] = g_map[i][j];
	}
	else if (OP == 2)
	{
		FOR(i, N)
		FOR(j, M) tmp[i][M - j - 1] = g_map[i][j];
	}
	else if (OP == 3)
	{
		FOR(j, M)
		D_FOR(i, N) tmp[j][N - 1 - i] = g_map[i][j];
		std::swap(N, M);
	}
	else if (OP == 4)
	{
		FOR(i, N)
		FOR(j, M) tmp[M - 1 - j][i] = g_map[i][j];
		std::swap(N, M);
	}
	else if (OP == 5)
	{
		int h_N = N / 2, h_M = M / 2;
		int s_y = 0, s_x = 0, n_y, n_x;

		FOR(k, 4)//direction
		{
		n_y = dy[k] * h_N, n_x = dx[k] * h_M;
		R_FOR(i, s_y, s_y + h_N)
		R_FOR(j, s_x, s_x + h_M) tmp[i + n_y][j + n_x] = g_map[i][j];
		s_y = s_y + dy[k] * h_N;
		s_x = s_x + dx[k] * h_M;
		}

	}
	else if (OP == 6)
	{
		int h_N = N / 2, h_M = M / 2;
		int s_y = 0, s_x = 0, n_y, n_x;

		FOR(k, 4)//direction
		{
		int dir = (5 - k) % 4;
		n_y = dy[dir] * h_N, n_x = dx[dir] * h_M;
		R_FOR(i, s_y, s_y + h_N)
		R_FOR(j, s_x, s_x + h_M) tmp[i + n_y][j + n_x] = g_map[i][j];
		s_y = s_y + dy[dir] * h_N;
		s_x = s_x + dx[dir] * h_M;
		}
	}
	std::memcpy(g_map, tmp, sizeof(g_map));
}

void solve()
{
	while (R--)
	{
		std::cin >> OP;
		rotate();
	}
}

void print_val()
{
	FOR(i, N){
	FOR(j, M) std::cout << g_map[i][j] << " ";
	std::cout << endl;}
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}

