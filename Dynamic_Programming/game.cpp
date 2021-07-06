//1103
#include <iostream>
#include <string>

int N, M;

std::string board[51];
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
int max_count[51][51];
int ans, limit;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> N >> M;
	for (int i = 0 ; i < N ; i++)
	{
		std::cin >> board[i];
		for (int j = 0 ; j < M ; j++)
		{
			if (board[i][j] == 'H')
				board[i][j] = -1;
			else
				board[i][j] -= '0';
		}
	}
	limit = N * M;
}

void dfs(int y, int x, int cnt)
{
	if (ans < cnt)
		ans = cnt;
	if (ans > limit)
		return;
	if (y < 0 || N <= y || x < 0 || M <= x || board[y][x] == -1)
		return;
	if (cnt <= max_count[y][x])
		return ;
	max_count[y][x] = cnt;
	int mul = board[y][x];
	for (int i = 0 ; i < 4 ; i++)
		dfs(y + dy[i] * mul, x + dx[i] * mul, cnt + 1);

}

void solve()
{
	for (int i = 0 ; i < N  ; i++)
		for (int j = 0 ; j < M ; j++)
			max_count[i][j] = -1;
	dfs(0, 0, 0);
	if (ans > limit)
		ans = -1;
	std::cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}
