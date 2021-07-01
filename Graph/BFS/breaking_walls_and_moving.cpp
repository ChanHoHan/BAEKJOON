//2206
#include <iostream>
#include <queue>

int N, M;
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
char g_map[1001][1001];
bool visited[2][1001][1001];
int ans = -1;
std::queue<std::pair<std::pair<int, int>, std::pair<int, int> > >q; // second pair-> distance, flag

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

void bfs()
{
	int qy, qx, ny, nx, distance, flag;

	q.push({{0,0}, {1,0}});
	visited[0][0][0] = 1;
	while(!q.empty())
	{
		qy = q.front().first.first;
		qx = q.front().first.second;
		distance = q.front().second.first;
		flag = q.front().second.second;
		q.pop();
		for (int i = 0 ; i < 4 ; i++)
		{
			ny = qy + dy[i];
			nx = qx + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;
			if (flag && (g_map[ny][nx] == '1'))
				continue;
			if (ny == N - 1 && nx == M - 1)
			{
				ans = distance + 1;
				return ;
			}
			if (g_map[ny][nx] == '1')
			{
				if (visited[1][ny][nx])
					continue;
				visited[1][ny][nx] = 1;
				q.push({{ny, nx}, {distance + 1, 1}});
			}
			else
			{
				if (visited[flag][ny][nx])
					continue;
				visited[flag][ny][nx] = 1;
				q.push({{ny, nx}, {distance + 1, flag}});
			}
		}
	}
}

void solve()
{
	if (N == 1 && M == 1)
	{
		ans = 1;
		return ;
	}
	bfs();
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
