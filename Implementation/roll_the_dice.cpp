//14499
#include <iostream>
#define endl "\n"

int g_map[21][21];
int command[1001];
int x, y;
int N, M, K;
int dx[5] = {0, 0, 0, -1, 1}; // ind 0 padding
int dy[5] = {0, 1, -1, 0, 0};
int left, right, up, down, front, back;

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> N >> M >> x >> y >> K;
	for (int i = 0 ; i < N ; i++)
		for(int j = 0 ; j < M  ; j++)
			std::cin >> g_map[i][j];
	for (int i = 0 ; i < K ; i++)
		std::cin >> command[i];
	left = right = up = down = front = back = 0;
}

void move_east()
{
	int tmp, tmp2, tmp3;

	tmp = right;
	tmp2 = down;
	tmp3 = left;

	right = up;
	down = tmp;
	left = tmp2;
	up = tmp3;
}

void move_west()
{
	int tmp, tmp2, tmp3;

	tmp = left;
	tmp2 = down;
	tmp3 = right;

	left = up;
	down = tmp;
	right = tmp2;
	up = tmp3;
}

void move_north()
{
	int tmp, tmp2, tmp3;

	tmp = back;
	tmp2 = down;
	tmp3 = front;

	back = up;
	down = tmp;
	front = tmp2;
	up = tmp3;
}

void move_south()
{
	int tmp, tmp2, tmp3;

	tmp = front;
	tmp2 = down;
	tmp3 = back;

	front = up;
	down = tmp;
	back = tmp2;
	up = tmp3;
}

void move_dice(int dir)
{
	if (dir == 1) // 동
		move_east();
	else if (dir == 2)//서
		move_west();
	else if (dir == 3)//북
		move_north();
	else if (dir == 4)
		move_south();
}

void solve()
{
	int dir, m_x, m_y;

	for (int i = 0 ; i < K ; i++)
	{
		dir = command[i];
		m_x = x + dx[dir];
		m_y = y + dy[dir];
		if (m_x < 0 || m_x >= N || m_y < 0 || m_y >= M)
			continue;
		move_dice(dir);
		x = m_x;
		y = m_y;
		if (g_map[x][y] != 0)
		{
			down = g_map[x][y];
			g_map[x][y] = 0;
		}
		else if (!g_map[x][y])
			g_map[x][y] = down;
		std::cout << up << endl;
	}
}

int main()
{
	input();
	solve();
	return (0);
}

