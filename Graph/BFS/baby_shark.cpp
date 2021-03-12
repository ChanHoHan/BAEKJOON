#include <iostream>
#include <queue>
#include <string.h>
#include <tuple>

int space[21][21];
int shark_i, shark_j, shark_size, shark_level;
int N, ans;
int g_dx[4] = {0, 1, 0, -1};
int g_dy[4] = {1, 0, -1, 0};
bool visited[21][21];

std::queue<std::tuple<int, int, int> >q; //shark i , shark j , time

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
	for (int i = 1 ; i <= N ; i++)
		for (int j = 1 ; j <= N ; j++)
		{
			std::cin >> space[i][j];
			if (space[i][j] == 9)
			{
				space[i][j] = 0;
				shark_i = i;
				shark_j = j;
			}
		}
	ans = 0;
	shark_size = 2;
}

int count_fishes()
{
	int cnt = 0;

	for (int i = 1 ; i <= N ; i++)
		for (int j = 1 ; j <= N ; j++)
			if (space[i][j] && space[i][j] < shark_size)
				cnt++;
	return (cnt);
}

bool state_update(int f_t, int f_i, int f_j)
{
	if (f_t != 10000)
	{
		shark_i = f_i;
		shark_j = f_j;
		space[shark_i][shark_j] = 0;
		shark_level++;
		if (shark_level == shark_size)
		{
			shark_size++;
			shark_level = 0;
		}
		ans+=f_t;
		return (1);
	}
	else
		return (0);
}

int bfs()
{
	int q_i, q_j, q_t, f_i, f_j, f_t, dx, dy;

	f_i = 0;
	f_j = 0;
	f_t = 10000;
	q.push({shark_i, shark_j, 0});
	visited[shark_i][shark_j] = 1;
	while(!q.empty())
	{
		std::tuple<int, int, int> tmp = q.front();
		q.pop();
		q_i = std::get<0>(tmp);
		q_j = std::get<1>(tmp);
		q_t = std::get<2>(tmp);
		if (space[q_i][q_j] && space[q_i][q_j] < shark_size)
		{
			if (f_t > q_t)
			{
				f_t = q_t;
				f_i = q_i;
				f_j = q_j;
			}
			else if (f_t == q_t)
			{
				if (f_i > q_i)
				{
					f_i = q_i;
					f_j = q_j;
				}
				else if (f_i == q_i && f_j > q_j)
						f_j = q_j;
			}
			continue;
		}
		for (int x = 0 ; x < 4 ; x++)
		{
			dx = (q_i + g_dx[x]);
			dy = (q_j + g_dy[x]);
			if (visited[dx][dy] || dx <= 0 || dx > N || dy <= 0 || dy > N || space[dx][dy] > shark_size)
				continue;
			visited[dx][dy] = 1;
			q.push({dx, dy, q_t + 1});
		}
	}
	return (state_update(f_t, f_i, f_j));
}

void print_val()
{
	std::cout << ans;
}

void solve()
{
	while (count_fishes())
	{
		memset(visited, 0, sizeof(visited));
		q = std::queue<std::tuple<int, int, int> >();
		if(!bfs())
			break;
	}
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}

