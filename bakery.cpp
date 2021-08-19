//3109
#include <iostream>

int R, C;
char g_map[10005][505];
bool visited[10005][505];
int dx[3] = {1, 1, 1};
int dy[3] = {-1, 0, 1};
int ans;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

bool dfs(int y, int x)
{
	int ny, nx;
	if (x == C - 1) {
		ans++;
		return true;
	}
	for (int i = 0 ; i < 3 ; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx] || g_map[ny][nx] == 'x') continue;
		visited[ny][nx] = 1;
		if(dfs(ny, nx)) return true;
	}
	return false;
}

void input()
{
	io_faster();
	std::cin >> R >> C;
	for (int i = 0 ; i < R ; i++) std::cin >> g_map[i];
}

void solve()
{
	for(int i = 0 ; i < R ; i++) {
		dfs(i, 0);
	}
	std::cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}

