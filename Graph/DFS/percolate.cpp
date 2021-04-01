//13565
#include <iostream>

int N, M;
bool g_map[1001][1001];
bool visited[1001][1001];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int ans;

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	std::string a;

	input_faster();
	std::cin >> M >> N;
	for (int i = 0 ; i < M ; i++)
	{
		std::cin >> a;
		for (int j = 0; j < a.size() ; j++)
			g_map[i][j] = (int)a[j] - '0';
	}	
}

bool dfs(int y, int x)
{
	int ny, nx;

	for (int i = 0 ; i < 4 ; i++)
	{
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny >= M)
			return (1);
		if (ny < 0 || nx < 0 || nx >= N || visited[ny][nx] || g_map[ny][nx])
			continue;
		visited[ny][nx] = 1;
		if(dfs(ny, nx))
			return (1);
	}
	return (0);
}

void solve()
{
	for (int i = 0 ; i < N ; i++)
	{
		if (visited[0][i] || g_map[0][i])
			continue;
		visited[0][i] = 1;
		if(dfs(0, i))
		{
			ans = 1;
			return ;
		}
	}
}

void print_val()
{
	if (ans)
		std::cout << "YES";
	else
		std::cout << "NO";
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}

