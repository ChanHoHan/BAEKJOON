//16236
#include <iostream>
#include <cstring>

int N, M, k;
int smells[21][21];
int g_map[21][21];
int tmp_map[21][21];
int ans;
typedef struct s_shark
{
	int y;
	int x;
	int dir;
	int live;
	int priority_up[4];
	int priority_down[4];
	int priority_left[4];
	int priority_right[4];
} t_shark;
int dy[5] = {0, -1, 1, 0, 0};
int dx[5] = {0, 0, 0, -1, 1};
t_shark shark_info[401];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> N >> M >> k;
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < N ; j++)
		{
			std::cin >> g_map[i][j];
			if (g_map[i][j] >= 1)//shark coordinate
			{
				shark_info[g_map[i][j]].y = i;
				shark_info[g_map[i][j]].x = j;
				shark_info[g_map[i][j]].live = 1;
			}
		}
	for (int i = 1 ; i <= M ; i++)
		std::cin >> shark_info[i].dir;
	for (int i = 1 ; i <= M ; i++) // shark num
	{
		for (int j = 0 ; j < 4 ; j++)
			std::cin >> shark_info[i].priority_up[j];
		for (int j = 0 ; j < 4 ; j++)
			std::cin >> shark_info[i].priority_down[j];
		for (int j = 0 ; j < 4 ; j++)
			std::cin >> shark_info[i].priority_left[j];
		for (int j = 0 ; j < 4 ; j++)
			std::cin >> shark_info[i].priority_right[j];
	}
}

void smells_decreased()
{
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < N ; j++)
			if (smells[i][j] > 0)
			{
				smells[i][j]--;
				if (!smells[i][j])
					g_map[i][j] = 0;
			}
}

void smells_spray()
{
	for (int i = 1 ; i <= M ; i++)
	{
		if (!shark_info[i].live)
			continue;
		smells[shark_info[i].y][shark_info[i].x] = k;
		g_map[shark_info[i].y][shark_info[i].x] = i;
	}
}

bool can_go(int num, int *p)
{
	int ny, nx, y = shark_info[num].y, x = shark_info[num].x;

	for (int i = 0 ; i < 4; i++)
	{
		ny = dy[p[i]] + y;
		nx = dx[p[i]] + x;
		if (ny < 0 || ny >= N || nx < 0 || nx >= N || smells[ny][nx])
			continue;
		shark_info[num].dir = p[i];
		return (1);
	}
	return (0);
}

void find_shark_direction(int num, int *p)
{
	int ny, nx, y = shark_info[num].y, x = shark_info[num].x;

	for (int i = 0 ; i < 4 ; i++)
	{
		ny = dy[p[i]] + y;
		nx = dx[p[i]] + x;	
		if (ny < 0 || ny >= N || nx < 0 || nx >= N || g_map[ny][nx] != num)
			continue;
		shark_info[num].dir = p[i];
		return;
	}
}

void direction_judgment()
{
	for (int i = 1 ; i <= M ; i++)
	{
		if (!shark_info[i].live)
			continue;
		if (shark_info[i].dir == 1)
		{
			if (!can_go(i, shark_info[i].priority_up))
				find_shark_direction(i, shark_info[i].priority_up);
		}
		else if (shark_info[i].dir == 2)
		{
			if (!can_go(i, shark_info[i].priority_down))
				find_shark_direction(i, shark_info[i].priority_down);
		}
		else if (shark_info[i].dir == 3)
		{
			if (!can_go(i, shark_info[i].priority_left))
				find_shark_direction(i, shark_info[i].priority_left);
		}
		else if (shark_info[i].dir == 4)
		{
			if (!can_go(i, shark_info[i].priority_right))
				find_shark_direction(i, shark_info[i].priority_right);
		}
	}
}

void shark_move()
{
	int y, x, ny, nx;
	memset(tmp_map, 0, sizeof(tmp_map));
	for (int i = 1 ; i <= M ; i++)
	{
		if (!shark_info[i].live)
			continue;
		y = shark_info[i].y;
		x = shark_info[i].x;
		ny = y + dy[shark_info[i].dir];
		nx = x + dx[shark_info[i].dir];
		if (tmp_map[ny][nx])
		{
			shark_info[i].live = 0;
			continue;
		}
		tmp_map[ny][nx] = i;
		shark_info[i].y = ny;
		shark_info[i].x = nx;
		g_map[ny][nx] = i;
	}	
}

bool one_shark_check()
{
	int cnt = 0;

	for (int i = 1; i <= M ; i++)
	{
		if (shark_info[i].live)
			cnt++;
	}
	if (cnt == 1)
		return (0);
	return (1);
}

void solve()
{
	int t = -1;
	while (++t <= 1000 && one_shark_check())
	{
		smells_decreased();
		smells_spray();
		direction_judgment();
		shark_move();
	}
	if (t == 1001)
		ans = -1;
	else
		ans = t;
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
