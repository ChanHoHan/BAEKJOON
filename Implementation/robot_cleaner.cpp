//14503
#include <iostream>

int N, M;
bool visited[51][51];
bool g_map[51][51];

int r_i, r_j, r_d;
int ans;
int step_two(int cnt);

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> N >> M;
	std::cin >> r_i >> r_j >> r_d;
	for(int i = 0 ; i < N; i++)
		for(int j = 0 ; j < M ; j++)
			std::cin >> g_map[i][j];
	ans = 0;
}

void step_one()
{
	visited[r_i][r_j] = 1;
	ans++;
	step_two(0);
}

std::pair<int, int> step_two_left_direction(int i, int j)
{
	if (r_d == 0)//북
		return (std::make_pair(i, j - 1));
	else if (r_d == 1)//동
		return (std::make_pair(i - 1, j));
	else if (r_d == 2)//남
		return (std::make_pair(i, j + 1));
	else//서
		return (std::make_pair(i + 1, j)); 
}

std::pair<int, int> step_two_back(int i, int j)
{
	if (r_d == 0)//북
		return (std::make_pair(i + 1, j));
	else if (r_d == 1)//동
		return (std::make_pair(i, j - 1));
	else if (r_d == 2)//남
		return (std::make_pair(i - 1, j));
	else//서
		return (std::make_pair(i, j + 1)); 

}

void step_two_direction_left_change()
{
	if (r_d == 0)//북
		r_d = 3;
	else if (r_d == 1)//동
		r_d = 0;
	else if (r_d == 2)//남
		r_d = 1;
	else//서
		r_d = 2; 
}

int step_two(int cnt)
{
	std::pair<int, int>left = step_two_left_direction(r_i, r_j);
	int dy = left.first;
	int dx = left.second;
	if (dy < 0 || dy >= N || dx < 0 || dx >= M || g_map[dy][dx] || visited[dy][dx]) 
	{
		if (cnt == 4)
		{
			std::pair<int, int>back = step_two_back(r_i, r_j);
			dy = back.first;
			dx = back.second;
			if (dy < 0 || dy >= N || dx < 0 || dx >= M || g_map[dy][dx])
			{
				std::cout << ans;
				return (5);
			}
			r_i = dy;
			r_j = dx;
			step_two(0);
		}
		else
		{
			step_two_direction_left_change();
			step_two(cnt + 1);
		}
	}
	else
	{
		step_two_direction_left_change();
		r_i = dy;
		r_j = dx;
		step_one();
	}
	return (5);
}

void solve()
{
	step_one();
}

int main()
{
	input();
	solve();
	return (0);
}

