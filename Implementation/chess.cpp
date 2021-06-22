//1986
#include <iostream>
#define endl "\n"
#define QUEEN 2
#define KNIGHT 3
#define PAWN 4

int n, m, queen_size, pawn_size, knight_size;
int g_map[1001][1001];
int q_dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int q_dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int k_dy[4][2] = {{-1, 1}, {1, 1}, {-1, 1}, {-1, -1}};
int k_dx[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	int r, c;

	io_faster();
	std::cin >> n >> m;
	std::cin >> queen_size;
	for (int i = 0 ; i < queen_size ; i++)
	{
		std::cin >> r >> c;
		g_map[r][c] = QUEEN;
	}
	std::cin >> knight_size;
	for (int i = 0 ; i < knight_size ; i++)
	{
		std::cin >> r >> c;
		g_map[r][c] = KNIGHT;
	}
	std::cin >> pawn_size;
	for (int i = 0 ; i < pawn_size ; i++)
	{
		std::cin >> r >> c;
		g_map[r][c] = PAWN;
	}
}

void queen_op(int r, int c)
{
	int ny, nx;

	for (int i = 0 ; i < 8 ; i++)
	{
		ny = r + q_dy[i];
		nx = c + q_dx[i];
		while (ny > 0 && ny <= n && nx > 0 && nx <= m && g_map[ny][nx] <= 1)
		{
			g_map[ny][nx] = 1;
			ny += q_dy[i];
			nx += q_dx[i];
		}
	}
}

void knight_op(int r, int c)
{
	int ny, nx, kny, knx;

	for (int i = 0 ; i < 4 ; i++)
	{
		ny = r + dy[i];
		nx = c + dx[i];
		if (ny <= 0 || ny > n || nx <= 0 || nx > m )
			continue;
		for (int j = 0 ; j < 2 ; j++)
		{
			kny = ny + k_dy[i][j];
			knx = nx + k_dx[i][j];
			if (kny <= 0 || kny > n || knx <= 0 || knx > m || g_map[kny][knx] >= 2)
				continue;
			g_map[kny][knx] = 1;
		}
	}
}

void solve()
{
	int ans = 0;

	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 1 ; j <= m ; j++)
		{
			if (g_map[i][j] >= 2)
			{
				if (g_map[i][j] == QUEEN)
					queen_op(i, j);
				else if (g_map[i][j] == KNIGHT)
					knight_op(i, j);
			}
		}
	}

	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 1 ; j <= m ; j++)
		{
			if (!g_map[i][j])
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
