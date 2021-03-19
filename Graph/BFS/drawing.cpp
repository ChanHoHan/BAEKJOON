//1926
#include <iostream>
#include <queue>
#include <algorithm>

#define endl "\n"

int n, m;
bool board[501][501];
bool visited[501][501];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int cnt, max_val;
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
	std::cin >> n >> m;
	for (int i = 0 ; i < n ; i++)
		for (int j = 0 ; j < m ; j++)
			std::cin >> board[i][j];
}

void bfs(int i, int j)
{
	int y, x, q_y, q_x;

	if (visited[i][j] || !board[i][j])
		return ;
	int area = 0;
	visited[i][j] = 1;
	cnt++;
	q = std::queue<std::pair<int, int> >();
	q.push({i, j});
	area++;
	while (!q.empty())
	{
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int k = 0 ; k < 4 ; k++)
		{
			q_y = y + dy[k];
			q_x = x + dx[k];
			if (q_y < 0 || q_y >= n || q_x < 0 || q_x >= m || visited[q_y][q_x] || !board[q_y][q_x])
				continue;
			visited[q_y][q_x] = 1;
			q.push({q_y, q_x});
			area++;
		}
	}
	max_val = std::max(max_val, area);
}

void solve()
{
	for(int i = 0 ; i < n ; i++)
		for (int j = 0 ; j < m ; j++)
			bfs(i, j);
}

void print_val()
{
	std::cout << cnt << endl;
	std::cout << max_val;
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}

