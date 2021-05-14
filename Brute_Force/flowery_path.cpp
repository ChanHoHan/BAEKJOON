//14620
#include <iostream>

int g_map[11][11];
bool visited[11][11];
int N, ans = 10 * 10 * 200;
const int dy[4] = {0,0,1,-1};
const int dx[4] = {1,-1,0,0};

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
			std::cin >> g_map[i][j];
}

void brute(int y, int x, int flower, int cnt)
{
	int ny, nx, fl;
	
	if (flower == 3)
	{
		if (ans > cnt)
			ans = cnt;
		return;
	}
	for (int i = y ; i < N - 1 ; i++)
		for (int j = 0 ; j < N - 1; j++)
		{
			fl = 0;
			if (visited[i][j])
				continue;
			for (int k = 0 ; k < 4 ; k++)
			{
				ny = dy[k] + i;
				nx = dx[k] + j;
				if (ny < 0  || ny >= N || nx < 0 || nx >= N || visited[ny][nx])
				{
					fl = 1;
					break;
				}
			}
			if (fl)
				continue;
			for (int k = 0 ; k < 4 ; k++)
			{
				ny = dy[k] + i;
				nx = dx[k] + j;
				cnt+=g_map[ny][nx];
				visited[ny][nx] = 1;
			}
			visited[i][j] = 1;
			cnt+=g_map[i][j];
			brute(i, j + 1, flower + 1, cnt);
			for (int k = 0 ; k < 4 ; k++)
			{
				ny = dy[k] + i;
				nx = dx[k] + j;
				cnt -= g_map[ny][nx];
				visited[ny][nx] = 0;
			}
			visited[i][j] = 0;
			cnt -= g_map[i][j];
		}
}

void solve()
{
	brute(1, 1, 0, 0);
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
