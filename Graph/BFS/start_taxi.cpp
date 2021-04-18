//19238
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

int N, M;
int g_map[21][21];
int visited[21][21];
int t_y, t_x, t_gas;
std::vector<std::pair<int, int> >guests;
std::vector<std::pair<std::pair<int, int>, int> >guests_save;
std::queue<std::pair<int, int> >q;
std::pair<int, int> dest;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int dest_y, dest_x;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	int g_y, g_x;

	io_faster();
	std::cin >> N >> M >> t_gas;
	for (int i = 1 ; i <= N ; i++)
		for (int j = 1 ; j <= N ; j++)
			std::cin >> g_map[i][j];
	std::cin >> t_y >> t_x;
	guests.resize(M + 2);
	for (int i = 0 ; i < M ; i++)
	{
		std::cin >> g_y >> g_x;
		g_map[g_y][g_x] = i + 2;
		std::cin >> guests[i + 2].first >> guests[i + 2].second;
	}
}

bool compare(std::pair<std::pair<int, int>, int> a, std::pair<std::pair<int, int>, int>b)
{
	if (a.first.first == b.first.first)
		return (a.first.second < b.first.second);
	return (a.first.first < b.first.first);
}


bool find_guest()
{
	int qy, qx, ny, nx, dist;

	std::memset(visited, -1, sizeof(visited));
	q = std::queue<std::pair<int, int> >();
	guests_save = std::vector<std::pair<std::pair<int, int>, int> > ();
	q.push({t_y, t_x});
	visited[t_y][t_x] = 0;
	dist = 0;
	if (g_map[t_y][t_x] > 1)
		guests_save.push_back({{t_y, t_x}, g_map[t_y][t_x]});
	else
	{
		while(!q.empty())
		{
			qy = q.front().first;
			qx = q.front().second;
			q.pop();
			if (visited[qy][qx] >= dist && guests_save.size())
				break;
			for (int i = 0 ; i < 4 ; i++)
			{
				ny = qy + dy[i];
				nx = qx + dx[i];
				if (ny <= 0 || ny > N || nx <= 0 || nx > N || visited[ny][nx] >= 0 || g_map[ny][nx] == 1)
					continue ;
				visited[ny][nx] = visited[qy][qx] + 1;
				if (g_map[ny][nx] > 1)
				{
					guests_save.push_back({{ny, nx}, g_map[ny][nx]});
					dist = visited[ny][nx];
				}
				q.push({ny, nx});
			}
		}
	}
	if (!guests_save.size() || dist > t_gas)
		return (0);
	t_gas -= dist; // 승객이 있는 곳으로 택시 이동
	std::sort(guests_save.begin(), guests_save.end(), compare);
	t_y = guests_save[0].first.first;
	t_x = guests_save[0].first.second;
	dest_y = guests[guests_save[0].second].first;
	dest_x = guests[guests_save[0].second].second;
	g_map[t_y][t_x] = 0; // 손님 태웠으므로
	return (1);
}

bool taxi_move_to_dest()
{
	int qy, qx, ny, nx;

	q = std::queue<std::pair<int, int> >();
	std::memset(visited, -1, sizeof(visited));
	q.push({t_y, t_x});
	visited[t_y][t_x] = 0;
	if (t_y == dest_y && t_x == dest_x)
		return (1);
	else
	{
		while(!q.empty())
		{
			qy = q.front().first;
			qx = q.front().second;
			q.pop();
			for (int i = 0 ; i < 4 ; i++)
			{
				ny = qy + dy[i];
				nx = qx + dx[i];
				if (ny <= 0 || ny > N || nx <= 0 || nx > N || visited[ny][nx] >= 0 || g_map[ny][nx] == 1)
					continue;
				visited[ny][nx] = visited[qy][qx] + 1;
				if (ny == dest_y && nx == dest_x)
				{
					t_gas -= visited[ny][nx];
					if (t_gas < 0)
						return (0);
					t_gas += visited[ny][nx] * 2;
					t_y = ny;
					t_x = nx;
					return (1);
				}
				q.push({ny, nx});
			}
		}
	}
	return (0);
}

bool taxi_operation()
{
	if (!find_guest())
		return (0);
	if(!taxi_move_to_dest())
		return (0);
	return (1);
}

void solve()
{
	int _M = M;
	while (_M--)
	{
		if(!taxi_operation())
		{
			t_gas = -1;
			return ;
		}
	}
}

void print_val()
{
	std::cout << t_gas;
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}

