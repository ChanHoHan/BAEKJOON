//15683
#include <iostream>
#include <vector>
#include <algorithm>

int N, M;
int g_map[10][10];

int one_y[4] = {0, 1, 0, -1};
int one_x[4] = {1, 0, -1, 0};
int two_y[2][2] = {{0, 0}, {1, -1}};
int two_x[2][2] = {{1, -1}, {0, 0}};
int three_y[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int three_x[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int four_y[4][3] = {{0, -1, 0}, {-1, 0, 1}, {0, 1, 0}, {1, 0, -1}};
int four_x[4][3] = {{-1, 0, 1}, {0, 1, 0}, {1, 0, -1}, {0, -1, 0}};
int five_y[1][4] = {{0, -1, 0, 1}};
int five_x[1][4] = {{1, 0, -1, 0}};

std::vector<std::pair<int, int> >cctv;
int ans;

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
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < M ; j++)
		{
			std::cin >> g_map[i][j];
			if (g_map[i][j] >= 1 && g_map[i][j] <= 5)
				cctv.push_back({i, j});
		}
	ans = 9999;
}

void shoot_operation(int y, int x, int dy, int dx, int ind)
{
	int nx, ny;

	nx = x + dx;
	ny = y + dy;
	if (nx < 0 || nx >= M || ny < 0 || ny >= N || g_map[ny][nx] == 6)
		return ;
	if (g_map[ny][nx])
		shoot_operation(ny, nx, dy, dx, ind);
	else
	{
		g_map[ny][nx] = ind;
		shoot_operation(ny, nx, dy, dx, ind);
	}
}

void shoot_back_operation(int y, int x, int dy, int dx, int ind)
{
	int nx, ny;
	nx = x + dx;
	ny = y + dy;
	if (nx < 0 || nx >= M || ny < 0 || ny >= N)
		return ;
	if (g_map[ny][nx] == ind)
		g_map[ny][nx] = 0;
	shoot_back_operation(ny, nx, dy, dx, ind);
}

void cal_blind_spot()
{
	int cnt = 0;

	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < M ; j++)
			if (!g_map[i][j])
				cnt++;
	ans = std::min(ans, cnt);
}

void brute_force(int ind)
{
	int y = cctv[ind].first;
	int x = cctv[ind].second;
	int g_map_val = g_map[y][x];
	
	if (ind == cctv.size())
	{
		cal_blind_spot();
		return ;
	}
	if (g_map_val == 1)
	{
		for (int i = 0 ; i < 4 ; i++)
		{
			shoot_operation(y, x, one_y[i], one_x[i], 10 + ind);
			brute_force(ind + 1);
			shoot_back_operation(y, x, one_y[i], one_x[i], 10 + ind);
		}
	}
	else if (g_map_val == 2)
	{
		for (int i = 0 ; i < 2 ; i++)
		{
			for (int j = 0 ; j < 2 ; j++)
				shoot_operation(y, x, two_y[i][j], two_x[i][j], 10 + ind);
			brute_force(ind + 1);
			for (int j = 0 ; j < 2 ; j++)
				shoot_back_operation(y, x, two_y[i][j], two_x[i][j], 10 + ind);
		}
	}
	else if (g_map_val == 3)
	{
		for (int i = 0 ; i < 4 ; i++)
		{
			for (int j = 0; j < 2 ; j++)
				shoot_operation(y, x, three_y[i][j], three_x[i][j], 10 + ind);
			brute_force(ind + 1);
			for (int j = 0 ; j < 2 ; j++)
				shoot_back_operation(y, x, three_y[i][j], three_x[i][j], 10 + ind);
		}
	}
	else if (g_map_val == 4)
	{
		for (int i = 0 ; i < 4 ; i++)
		{
			for (int j = 0 ; j < 3 ; j++)
				shoot_operation(y, x, four_y[i][j], four_x[i][j], 10 + ind);
			brute_force(ind + 1);
			for (int j = 0 ; j < 3; j++)
				shoot_back_operation(y, x, four_y[i][j], four_x[i][j], 10 + ind);
		}
	}
	else if (g_map_val == 5)
	{
		for (int i = 0 ; i < 4 ; i++)
			shoot_operation(y, x, five_y[0][i], five_x[0][i], 10 + ind);
		brute_force(ind + 1);
		for (int i = 0 ; i < 4 ; i++)
			shoot_back_operation(y, x, five_y[0][i] , five_x[0][i], 10 + ind);
	}
	
}

void solve()
{
	if (!cctv.size())
	{
		cal_blind_spot();
		return ;
	}
	brute_force(0);
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

