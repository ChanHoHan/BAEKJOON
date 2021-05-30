//16918
#include <iostream>
#include <queue>
#include <cstring>
#define endl "\n"
int R, C, N;
char g_map[201][201];
std::queue<std::pair<int, int> >q;
bool visited[201][201];
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> R >> C >> N;
	for (int i = 0 ; i < R ; i++)
		std::cin >> g_map[i];
	for (int i = 0 ; i < R ; i++)
		for (int j = 0 ; j < C ; j++)
		{
			if (g_map[i][j] == 'O')
				q.push({i, j});
			else
				visited[i][j] = 1;
		}
}

void boom()
{
	int q_y, q_x, ny, nx;
	
	std::memset(visited, 0, sizeof(visited));
	while (!q.empty())
	{
		q_y = q.front().first;
		q_x = q.front().second;
		q.pop();
		visited[q_y][q_x] = 1;
		for (int i = 0 ; i < 4; i++)
		{
			ny = q_y + dy[i];
			nx = q_x + dx[i];
			if (ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx])
				continue;
			visited[ny][nx] = 1;
		}
	}
	for (int i = 0 ; i < R ; i++)
		for (int j = 0 ; j < C ; j++)
			if (!visited[i][j])
				q.push({i,j});
}

void solve()
{
	int time = 0;
	int N_ = N;

	if (!(N % 2))
		return ;
	N_--;
	while(N_--)
	{
		if (time % 2)
			boom();
		time++;
	}
}

void print_val()
{
	if (!(N % 2))
	{
		for (int i = 0 ; i < R ; i++)
		{
			for (int j = 0 ; j < C ; j++)
				std::cout << "O";
			std::cout << endl;
		}
		return ;
	}
	
	for (int i = 0 ; i < R ; i++)
	{
		for (int j = 0 ; j < C ; j++)
		{
			if (visited[i][j])
				std::cout << ".";
			else
				std::cout << "O";
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
