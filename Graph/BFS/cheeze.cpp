//2636
#include <iostream>
#include <cstring>
#include <queue>
#define endl "\n"

int N, M;
bool g_map[102][102];
bool visited[102][102];
int save, ans;
std::queue<std::pair<int, int> >q;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> N >> M;
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < M ; j++)
			std::cin >> g_map[i][j];
	ans = 0;
}

int count_map()
{
	int cnt = 0;

	for (int i = 1 ; i <= N ; i++)
		for (int j = 1 ; j <= M ; j++)
			cnt += g_map[i][j];
	return (cnt);
}

void bfs()
{
	int y, x, ny, nx;
	q.push({0, 0});
	visited[0][0] = 1;
	while(!q.empty())
	{
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0 ; i < 4 ; i++)
		{
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || ny > N + 1 || nx < 0 || nx > M + 1 || visited[ny][nx])
				continue;
			visited[ny][nx] = 1;
			if (g_map[ny][nx] == 1)
			{
				g_map[ny][nx] = 0;
				continue;
			}
			q.push({ny, nx});
		}
	}
}

void solve()
{
	int tmp;
	save = 0;
	ans = 0;

	while ((tmp = count_map()))
	{
		save = tmp;
		std::memset(visited, 0, sizeof(visited));
		q = std::queue<std::pair<int, int> >();
		bfs();
		ans++;
	}
}

void print_val()
{
	std::cout << ans << endl;
	std::cout << save;
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}

