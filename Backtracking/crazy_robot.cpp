//1405
#include <iostream>

int N;
double pr[4];
int g_map[35][35];
bool visited[35][35];
double up, down;
int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	int tmp;

	io_faster();
	std::cin >> N;
	for (int i = 0 ; i < 4 ; i++)
	{
		std::cin >> tmp;
		pr[i] = tmp * 0.01;
	}
}

void dfs(int y, int x, int depth, double prob)
{
	int ny, nx;

	if (depth == N)
	{
		down += prob;
		up += prob;
		return;
	}
	for (int i = 0 ; i < 4 ; i++)
	{
		ny = y + dy[i];
		nx = x + dx[i];
		if(nx < 14 - N || nx > 14 + N || ny < 14 - N || ny > 14 + N)
			continue;
		if (visited[ny][nx])
		{
			down += prob * pr[i];
			continue;
		}
		visited[ny][nx] = 1;
		dfs(ny, nx, depth + 1, prob * pr[i]);
		visited[ny][nx] = 0;
	}
}

void solve()
{
	visited[14][14] = 1;
	dfs(14, 14, 0, 1.0);
}

void print_val()
{
	std::cout << (up / down);
}

int main()
{
	input();
	std::cout << std::fixed;
	std::cout.precision(10);
	solve();
	print_val();
	return (0);
}
