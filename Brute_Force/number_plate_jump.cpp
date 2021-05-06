//2210
#include <iostream>
#include <string>
#define endl "\n"

char g_map[6][6];
bool visited[1000000];
const int dy[4] = {0, 0, 1, -1};
const int dx[4] = {1, -1, 0, 0};
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
	
	for (int i = 0 ; i < 5 ; i++)
		for (int j = 0 ; j < 5 ; j++)
			std::cin >> g_map[i][j];
}

void dfs(int y, int x, std::string val)
{
	int ny, nx;
	
	val += g_map[y][x];
	if (val.size() == 6)
	{
		if (!visited[std::stoi(val)])
		{
			ans++;
			visited[std::stoi(val)] = 1;
		}
		return;
	}
	for (int i = 0 ; i < 4 ; i++)
	{
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5)
			continue;
		dfs(ny, nx, val);
	}
}

void solve()
{
	for (int i = 0 ; i < 5 ; i++)
		for (int j = 0 ; j < 5 ; j++)
			dfs(i, j, "");
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

