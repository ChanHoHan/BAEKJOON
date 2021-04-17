//16948
#include <iostream>
#include <queue>
#include <cstring>

int N, r1, c1, r2, c2;
int dy[6] = {-2, -2, 0, 0, 2, 2};
int dx[6] = {-1, 1, -2, 2, -1, 1};
int visited[201][201];
std::queue<std::pair<int, int> >q;
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
	std::cin >> N >> r1 >> c1 >> r2 >> c2;
	std::memset(visited, -1, sizeof(visited));
	ans = -1;
}

void bfs()
{
	int qx, qy, nx, ny;

	q.push({r1, c1});
	visited[r1][c1] = 0;
	while(!q.empty())
	{
		qy = q.front().first;
		qx = q.front().second;
		q.pop();
		for (int i = 0 ; i < 6 ; i++)
		{
			ny = qy + dy[i];
			nx = qx + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] >= 0)
				continue;
			if (ny == r2 && nx == c2)
			{
				ans = visited[qy][qx] + 1;
				return;
			}
			q.push({ny, nx});
			visited[ny][nx] = visited[qy][qx] + 1;
		}
	}
}

void solve()
{
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

