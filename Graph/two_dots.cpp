//16929
#include <iostream>

int N, M, start_y, start_x;
char g_map[51][51];
bool visited[51][51];
std::string ans = "No";
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

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
		std::cin >> g_map[i];
}

bool dfs(int y, int x, char color, int depth)
{
	int ny, nx;

	for (int i = 0 ; i < 4 ; i++)
	{
		ny = y + dy[i];
		nx = x + dx[i];
		if (depth >= 4 && ny == start_y && nx == start_x)
		{
			ans = "Yes";
			return (1);
		}
		if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || color != g_map[ny][nx])
			continue;
		visited[ny][nx] = 1;
		if (dfs(ny, nx, color, depth + 1))
			return (1);
		visited[ny][nx] = 0;
	}
	return (0);
}

void solve()
{
	for (int i = 0 ; i < N ; i++)
		for (int j = 0; j < M ; j++)
		{
			start_y = i;
			start_x = j;
			visited[i][j] = 1;
			if(dfs(i, j, g_map[i][j], 1))
				return;
			visited[i][j] = 0;
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
