//16928
#include <iostream>
#include <queue>

int N, M;
int ladder_snake[101];
bool visited[101];
int dice[6] = {1,2,3,4,5,6};
int ans;

std::queue<std::pair<int, int> > q; // 몇 번째 칸인지, 주사위 굴린 횟수

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	int x, y;

	input_faster();
	std::cin >> N >> M;
	for (int i = 0 ; i < N ; i++)
	{
		std::cin >> x >> y;
		ladder_snake[x] = y;
	}
	for (int i = 0 ; i < M ; i++)
	{
		std::cin >> x >> y;
		ladder_snake[x] = y;
	}
}

void bfs()
{
	int qx, qy, nx, ny;

	q.push({1, 0});
	visited[1] = 1;
	while (!q.empty())
	{
		qy = q.front().first; //몇 번째 칸인지
		qx = q.front().second; //주사위를 지금까지 얼마나 굴렸는지
		q.pop();
		for (int i = 0 ; i < 6 ; i++)
		{
			ny = qy + dice[i];
			nx = qx + 1;
			if (ny <= 0 || ny > 100 || visited[ny])
				continue;
			if (ny == 100)
			{
				ans = nx;
				return ;
			}
			visited[ny] = 1;
			if (ladder_snake[ny]) // 사다리, 뱀 칸이면
			{
				if (visited[ladder_snake[ny]])
					continue;
				visited[ladder_snake[ny]] = 1;
				q.push({ladder_snake[ny], nx});
			}
			else
				q.push({ny, nx});
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

