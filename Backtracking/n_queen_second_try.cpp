//9663
#include <iostream>
#define endl "\n"
int N, g_map[16][16], end;
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int ans;

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
	end = N * N;
}

void mark(int r, int c, int flag)
{
	int ny, nx;

	g_map[r][c] += flag;
	for (int i = 0 ; i < 8 ; i++)
	{
		ny = r;
		nx = c;
		while (true)
		{
			ny = ny + dy[i];
			nx = nx + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				break;
			g_map[ny][nx] += flag;
		}
	}
}

void backtracking(int y, int cnt)
{
	
	if (cnt == N)
	{
		ans++;
		return ;
	}
	if (y >= N)
		return ;
	for (int i = 0 ; i < N ; i++)
	{
		if (g_map[y][i])
			continue;
		mark(y, i, 1);
		backtracking(y + 1, cnt + 1);
		mark(y, i, -1);
	}
}

void solve()
{
	backtracking(0, 0);
	std::cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}
