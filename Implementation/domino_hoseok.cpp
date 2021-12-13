//20165
#include <iostream>
#include <queue>
#define endl "\n"
int N, M, R;
int original[101][101];
int g_map[101][101];
char attack[10001][3];
int defense[10001][2];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
std::queue<std::pair<std::pair<int, int>, int> >q;
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
	std::cin >> N >> M >> R;
	for (int i = 1 ; i <= N ; i++)
		for (int j = 1 ; j <= M ; j++)
		{
			std::cin >> g_map[i][j];
			original[i][j] = g_map[i][j];
		}
	for (int i = 1 ; i <= R ; i++)
	{
		std::cin >> attack[i][0] >> attack[i][1] >> attack[i][2];
		std::cin >> defense[i][0] >> defense[i][1];
	}
}

int get_dir_index(char ch)
{
	if (ch == 'E')		
		return (0);
	else if (ch == 'W')
		return (1);
	else if (ch == 'S')		
		return (2);
	else if (ch == 'N')
		return (3);
	return (-1);
}

void attack_simulation(int y, int x, int dir)
{
	int qy, qx, val;

	q = std::queue<std::pair<std::pair<int, int>, int> >();
	if (!g_map[y][x])
		return ;
	q.push({{y, x}, g_map[y][x]});
	g_map[y][x] = 0;
	ans++;
	while (!q.empty())
	{
		qy = q.front().first.first;
		qx = q.front().first.second;
		val = q.front().second;
		q.pop();
		val -= 1;
		qy += dy[dir];
		qx += dx[dir];
		while (val--)
		{
			if (qy <= 0 || qy > N || qx <= 0 || qx > M)
				break;
			if (g_map[qy][qx] > 0)
			{
				q.push({{qy, qx}, g_map[qy][qx]});
				g_map[qy][qx] = 0;
				ans++;
			}
			qy += dy[dir];
			qx += dx[dir];
		}
	}
}

void solve()
{
	int dir;
	for (int i = 1 ; i <= R ; i++)
	{
		dir = get_dir_index(attack[i][2]);
		if (dir == -1)
			continue;
		attack_simulation(attack[i][0] - '0', attack[i][1] - '0', dir);
		if (g_map[defense[i][0]][defense[i][1]])
			continue;
		g_map[defense[i][0]][defense[i][1]] = original[defense[i][0]][defense[i][1]];
	}
}

void print_val()
{
	std::cout << ans << endl;
	for (int i = 1 ; i <= N ; i++)
	{
		for (int j = 1 ; j <= M ; j++)
		{
			if (g_map[i][j])
				std::cout << 'S' << " ";
			else
				std::cout << 'F' << " ";
		}
		std::cout << endl;
	}
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}
