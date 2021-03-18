//2468
#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>

int N;
int height[102][102];
bool visited[102][102];
std::queue<std::pair<int,int> > q;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ans;

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> N;
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < N ; j++)
			std::cin >> height[i][j];
	ans = 1;
}

void flooding_action(int f_height)
{
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < N ; j++)
			if (height[i][j] <= f_height)
				height[i][j] = 0;
}

bool bfs(int b_height)
{
	int x, y, q_x, q_y, cnt;

	cnt = 0;
	memset(visited, 0, sizeof(visited));
	flooding_action(b_height);
	q = std::queue<std::pair<int, int> >();

	for(int i = 0 ; i < N ; i++)
	{
		for (int j = 0 ; j < N ; j++)
		{
			if (visited[i][j] || !height[i][j])
				continue;
			cnt++;
			q.push({i, j});
			visited[i][j] = 1;
			while(!q.empty())
			{
				y = q.front().first;
				x = q.front().second;
				q.pop();
				for (int k = 0 ; k < 4 ; k++)
				{
					q_y = y + dy[k];
					q_x = x + dx[k];
					if (q_y < 0 || q_x < 0 || q_y >= N || q_x >= N || visited[q_y][q_x] || !height[q_y][q_x])
						continue;
					visited[q_y][q_x] = 1;
					q.push({q_y, q_x});
				}
			}
		}
	}
	if (!cnt)
		return (0);
	ans = std::max(ans, cnt);
	return (1);
}

void solve()
{
	int i = 0;

	while (++i <= 100 && bfs(i))
		;
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

