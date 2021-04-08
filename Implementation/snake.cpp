//3190
#include <iostream>
#include <vector>
#include <deque>

int N, K, L;
bool g_map[101][101];
std::deque<std::pair<int, int> >dq;
std::vector<std::pair<int, char> >path_change;
int path_index;
int dy[4] = {-1, 0, 1, 0}; //NESW
int dx[4] = {0, 1, 0, -1};
int snake_dir = 1; // E
int sec = 0;

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	int a, b;

	input_faster();
	std::cin >> N >> K;
	for (int i = 0 ; i < K ; i++)
	{
		std::cin >> a >> b;
		g_map[a][b] = 1;
	}
	std::cin >> L;
	path_change.resize(L);
	for (int i = 0 ; i < L ; i++)
		std::cin >> path_change[i].first >> path_change[i].second;
	dq.push_back({1, 1});
}

void direction_control(char ch)
{
	if (ch == 'L')
		snake_dir = ((snake_dir + 3) % 4);
	else if (ch == 'D')
		snake_dir = ((snake_dir + 1) % 4);
}

void time_decrease()
{
	for (int i = path_index ; i < path_change.size() ; i++)
	{
		path_change[i].first -= 1;
		if (path_change[i].first == 0)
		{
			direction_control(path_change[i].second);
			path_index++;
		}
	}

}

bool snake_move()
{
	int y, x, ny, nx;

	y = dq.front().first;
	x = dq.front().second;
	ny = y + dy[snake_dir];
	nx = x + dx[snake_dir];
	sec++;
	if (ny <= 0 || ny > N || nx <= 0 || nx > N)
		return (0);
	for (const auto & i : dq)
		if (i.first == ny && i.second == nx)
			return (0);
	if (g_map[ny][nx])
	{
		dq.push_front({ny, nx});
		g_map[ny][nx] = 0;
	}
	else
	{
		dq.push_front({ny, nx});
		dq.pop_back();
	}
	if (path_index < path_change.size())
		time_decrease();
	return (1);
}

void solve()
{
	while (snake_move())
		;
}

void print_val()
{
	std::cout << sec; 
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}

