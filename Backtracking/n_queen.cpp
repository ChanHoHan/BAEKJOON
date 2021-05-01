//9663
#include <iostream>

int N, g_map[16][16];
int ans;
int dx[4] = {1, -1, 1, -1};
int dy[4] = {1, 1, -1, -1};

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

bool check(int y, int x)
{
	int nx, ny;

	for (int i = 0 ; i < N ; i++)
	{
		if (i == y)
			continue;
		if (g_map[i][x])
			return (0);
	}
	for (int i = 0 ; i < N ; i++)
	{
		if (i == x)
			continue;
		if (g_map[y][i])
			return (0);
	}
	for (int i = 0 ; i < 4 ; i++)
	{
		ny = y + dy[i];
		nx = x + dx[i];
		while (true)
		{
			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				break;
			if (g_map[ny][nx])
				return (0);
			ny += dy[i];
			nx += dx[i];
		}
	}
	return (1);
}


void backtracking(int cnt, int y)
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
		if (check(y, i))
		{
			g_map[y][i] = 1;
			backtracking(cnt + 1, y + 1);
			g_map[y][i] = 0;
		}
	}
}

void solve()
{
	backtracking(0, 0);
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
