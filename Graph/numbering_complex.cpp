//2667
#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

int N;

int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
char g_map[26][26];
bool visited[26][26];
std::vector<int> ans;

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
	for (int i = 0 ; i < N ; i++)
		std::cin >> g_map[i];
}

void dfs(int y, int x, int &cnt)
{
	int ny,nx;

	for (int i = 0 ; i < 4 ; i++)
	{
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] || g_map[ny][nx] == '0')
			continue;
		visited[ny][nx] = 1;
		cnt+=1;
		dfs(ny, nx, cnt);
	}
}

void solve()
{
	int cnt;

	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < N ; j++)
			if (!visited[i][j] && g_map[i][j] == '1')
			{
				cnt = 1;
				visited[i][j] = 1;
				dfs(i, j, cnt);
				ans.push_back(cnt);
			}
}

void print_val()
{
	std::cout << ans.size() << endl;
	std::sort(ans.begin(), ans.end());
	for (size_t i = 0 ; i < ans.size() ; i++)
		std::cout << ans[i] << endl;
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}
