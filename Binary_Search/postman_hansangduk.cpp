//2842
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

int N, h[51][51], k_cnt, y_post, x_post;
char vil[51][51];
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
bool visited[51][51];
std::vector<int> height;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

int dfs(int low, int high, int y, int x)
{
	int val = 0, ny, nx;

	if (vil[y][x] == 'K')
		val = 1;
	for (int i = 0 ; i < 8 ; i++)
	{
		ny = dy[i] + y;
		nx = dx[i] + x;
		if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] || low > h[ny][nx] || high < h[ny][nx])
			continue;
		visited[ny][nx] = 1;
		val += dfs(low, high, ny, nx);
	}
	return (val);
}

void input()
{
	io_faster();
	std::cin >> N;
	for (int i = 0 ; i < N ; i++)
		std::cin >> vil[i];
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < N ; j++)
		{
			if (vil[i][j] == 'P')
			{
				y_post = i;
				x_post = j;
			}
			else if (vil[i][j] == 'K')
				k_cnt++;
		}

	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < N ; j++)
		{
			std::cin >> h[i][j];
			height.push_back(h[i][j]);
		}
	std::sort(height.begin(), height.end());
}

void solve()
{
	int low = 0, high = 0, val, ans = height.back() - height[0], h_size = height.size();

	while (high < h_size)
	{
		std::memset(visited, 0, sizeof(visited));
		visited[y_post][x_post] = 1;
		val = 0;
		if (height[low] <= h[y_post][x_post] && h[y_post][x_post] <= height[high])
			val = dfs(height[low], height[high], y_post, x_post);
		if (val == k_cnt)
		{
			if (ans > (height[high] - height[low]))
			{
				ans = height[high] - height[low];
			}
			low++;
		}
		else
			high++;
		if (low > high)
			high = low;
	}
	std::cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}
