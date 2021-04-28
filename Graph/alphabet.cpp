//1987
#include <iostream>

int R, C;
char g_map[21][21];
int visited[21][21];
int dy[4] = {1, -1 , 0 ,0};
int dx[4] = {0, 0, 1, -1};
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
	std::cin >> R >> C;
	for (int i = 0 ; i < R ; i++)
		std::cin >> g_map[i];
}

void dfs(int y, int x, int record, int cnt)
{
	if (ans < cnt)
		ans = cnt;
	for (int i = 0 ; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= R || nx < 0 || nx >= C || record & (1 << (g_map[ny][nx] - 'A')) || visited[ny][nx])
			continue;
		visited[ny][nx] = 1;
		dfs(ny, nx, record | (1 << (g_map[ny][nx] - 'A')), cnt + 1);
		visited[ny][nx] = 0;
	}
}

void solve()
{
	visited[0][0] = 1;
	dfs(0, 0, (1 << (g_map[0][0] - 'A')), 1);
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

