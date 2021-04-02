//1743
#include <iostream>
#include <queue>

int N, M, K, ans;
bool g_map[101][101];
bool visited[101][101];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
std::queue<std::pair<int, int> >q;

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	int y,x;

	std::cin >> N >> M >> K;
	for (int i = 0 ; i < K ; i++)
	{
		std::cin >> y >> x;
		g_map[y][x] = 1;
	}
}

void bfs(int y, int x)
{
	int qy,qx,ny,nx;
	int cnt = 1;

	visited[y][x] = 1;
	q.push({y, x});
	while(!q.empty())
	{
		qy = q.front().first;
		qx = q.front().second;
		q.pop();
		for (int i = 0 ; i < 4 ; i++)
		{
			ny = qy + dy[i];
			nx = qx + dx[i];
			if (ny <= 0 || ny > N || nx <= 0 || nx > M || visited[ny][nx] || !g_map[ny][nx])
				continue;
			visited[ny][nx] = 1;
			q.push({ny, nx});
			cnt++;
			if (cnt > ans)
				ans = cnt;
		}
	}
}
void solve()
{
	for (int i = 1 ; i <= N ; i++)
		for (int j = 1 ; j <= M ; j++)
			if (!visited[i][j] && g_map[i][j])
				bfs(i, j);
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

