//14500
#include <iostream>
#include <cstring>
#include <algorithm>

int N, M;
int g_map[501][501];
int tmp[501][501];
int ans;

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> N >> M;
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < M ; j++)
			std::cin >> g_map[i][j];
}

inline void max_check(int obj)
{
	if (obj > ans)
		ans = obj;
}

inline void check(int i, int j)
{
	if (j <= M - 4)
		max_check(g_map[i][j + 3] + g_map[i][j + 2] + g_map[i][j + 1] + g_map[i][j]);
	if (i <= N - 2 && j <= M - 2)
		max_check(g_map[i][j] + g_map[i][j + 1] + g_map[i + 1][j] + g_map[i + 1][j + 1]);
	if (i <= N - 3 && j <= M - 2)
	{
		max_check(g_map[i][j] + g_map[i + 1][j] + g_map[i + 2][j] + g_map[i + 2][j + 1]);
		max_check(g_map[i][j] + g_map[i + 1][j] + g_map[i + 1][j + 1] + g_map[i + 2][j + 1]);
		max_check(g_map[i][j + 1] + g_map[i + 1][j + 1] + g_map[i + 2][j + 1] + g_map[i + 2][j]);
		max_check(g_map[i][j + 1] + g_map[i + 1][j + 1] + g_map[i + 1][j] + g_map[i + 2][j]);
	}
	if (i <= N - 2 && j <= M - 3)
		max_check(g_map[i][j] + g_map[i][j + 1] + g_map[i][j + 2] + g_map[i + 1][j + 1]);
}

inline void rotate_map()
{
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < M ; j++)
			tmp[M - 1 - j][i] = g_map[i][j];
	std::swap(N, M);
}

void solve()
{
	for (int k = 0 ; k < 4 ; k++)
	{
		for (int i = 0 ; i < N ; i++)
			for (int j = 0 ; j < M ;j++)
				check(i, j);
		rotate_map();
		std::memcpy(g_map, tmp, sizeof(g_map));
	}
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

