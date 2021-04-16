#include <iostream>
#include <cstring>
#include <queue>

int N;
char blind_map[101][101];
char normal_map[101][101];
bool visited[101][101];
std::queue<std::pair<int, int> > q;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int n_ans, b_ans;

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
		for (int j = 0 ; j < N ; j++)
		{
			std::cin >> normal_map[i][j];
			if (normal_map[i][j] == 'R')
				blind_map[i][j] = 'G';
			else
				blind_map[i][j] = normal_map[i][j];
		}
}

void bfs(int y, int x, char (&g_map)[101][101])
{
	int qy, qx, ny, nx;

	visited[y][x] = 1;
	q.push({y,x});
	while(!q.empty())
	{
		qy = q.front().first;
		qx = q.front().second;
		q.pop();
		for (int i = 0 ; i < 4 ; i++)
		{
			ny = qy + dy[i];
			nx = qx + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] || g_map[y][x] != g_map[ny][nx])
				continue;
			q.push({ny, nx});
			visited[ny][nx] = 1;
		}
	}
}

void solve()
{
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < N ; j++)
			if (!visited[i][j])
			{
				bfs(i, j, normal_map);
				n_ans++;
			}
	std::memset(visited, 0, sizeof(visited));
	for (int i =  0 ; i < N ; i++)
		for (int j = 0 ; j < N ; j++)
			if (!visited[i][j])
			{
				bfs(i, j, blind_map);
				b_ans++;
			}
}

void print_val()
{
	std::cout << n_ans << " " << b_ans;
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}
