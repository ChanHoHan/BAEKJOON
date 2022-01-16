//18404
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
int N, M, X, Y;
int dx[9] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[9] = {-1, 1, -2, 2, -2, 2, -1, 1};
int visited[501][501];

void input()
{
	FASTIO;
	cin >> N >> M;
	cin >> X >> Y;
}

void solve()
{
	int r_x, r_y, ny, nx, qy, qx, q_size, phase;

	queue<pair<int, int> >q;
	q.push({X, Y});
	q_size = 1;
	phase = 0;
	memset(visited, 0, sizeof(visited));
	while (!q.empty())
	{
		for (int j = 0 ; j < q_size ; j++)
		{
			qx = q.front().first;
			qy = q.front().second;
			q.pop();
			for (int k = 0 ; k < 8 ; k++)
			{
				nx = qx + dx[k];
				ny = qy + dy[k];
				if (nx <= 0 || nx > N || ny <= 0 || ny > N || visited[nx][ny])
					continue;
				visited[nx][ny] = phase + 1;
				q.push({nx, ny});
			}
		}
		q_size = q.size();
		phase++;
	}
	for (int i = 0 ; i < M ; i++)
	{
		cin >> r_x >> r_y;
		cout << visited[r_x][r_y] << " " ;
	}
}

int main()
{
	input();
	solve();
	return (0);
}
