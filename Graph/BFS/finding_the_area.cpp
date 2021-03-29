//2583
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define endl "\n"
int M, N, K;
int g_map[102][102];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
std::queue<std::pair<int, int> >q;
std::vector<int> ans;
int numbers;

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	int x1, y1, x2, y2;

	input_faster();
	std::cin >> M >> N >> K;
	for (int i = 0 ; i < K ; i++)
	{
		std::cin >> x1 >> y1 >> x2 >> y2;
		for (int x = x1 ; x < x2 ; x++)
			for (int y = y1 ; y < y2 ; y++)
				g_map[x][y] = 1;
	}
}

void bfs(int i, int j)
{
	int y, x, ny, nx;
	int area = 0;

	if (g_map[i][j])
		return ;
	numbers++;
	q.push({i, j});
	g_map[i][j] = 1;
	while(!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		area++;
		for (int k = 0 ; k < 4; k++)
		{
			nx = x + dx[k];
			ny = y + dy[k];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || g_map[nx][ny])
				continue;
			g_map[nx][ny] = 1;
			q.push({nx, ny});
		}
	}
	ans.push_back(area);
}

void solve()
{
	for (int i = 0 ; i < N ; i++)
	{
		for (int j = 0 ; j < M ; j++)
		{
			bfs(i, j);
		}
	}
}

void print_val()
{
	std::cout << numbers << endl;
	std::sort(ans.begin(), ans.end());
	for(size_t i = 0 ; i < ans.size() ; i++)
		std::cout << ans[i] << " ";
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}

