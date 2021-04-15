//17135
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>

int N, M, D;
int g_map[16][16];
int cp_map[16][16];
int enemy_num;
int cp_enemy_num, kill_num;
std::vector<std::pair<int, int> >archor;
std::vector<std::pair<int, int> >can_kill_enemy;
std::vector<std::pair<int, int> >finally_kill_enemy;
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
	std::cin >> N >> M >> D;
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < M ; j++)
		{
			std::cin >> g_map[i][j];
			if (g_map[i][j])
				enemy_num++;
		}
}

bool comp(std::pair<int, int>a, std::pair<int, int>b)
{
	return (a.second < b.second);
}

int can_kill(int y, int x, int ey, int ex)
{
	int dist = std::abs(ey - y) + std::abs(ex - x);

	if (dist <= D)
		return (dist);
	return (0);
}

void kill_check(int y, int x)
{
	int min_dist = 999999, dist;

	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < M ; j++)
			if (cp_map[i][j] && (dist = can_kill(y, x, i, j)))
			{
				if (dist < min_dist)
				{
					can_kill_enemy.clear();
					can_kill_enemy.push_back({i, j});
					min_dist = dist;
				}
				else if (dist == min_dist)
					can_kill_enemy.push_back({i, j});
			}
}

void archer_kill()
{
	int y, x, ey, ex;

	finally_kill_enemy.clear();
	for (int i = 0 ; i < 3 ; i++)
	{
		can_kill_enemy.clear();
		y = archor[i].first;
		x = archor[i].second;
		kill_check(y, x);
		if (!can_kill_enemy.size())
			continue;
		std::sort(can_kill_enemy.begin(), can_kill_enemy.end(), comp);
		ey = can_kill_enemy[0].first;
		ex = can_kill_enemy[0].second;
		finally_kill_enemy.push_back({ey, ex});
	}
	for (size_t i = 0 ; i < finally_kill_enemy.size() ; i++)
	{
		ey = finally_kill_enemy[i].first;
		ex = finally_kill_enemy[i].second;
		if (!cp_map[ey][ex])
			continue;
		cp_map[ey][ex] = 0;
		cp_enemy_num--;
		kill_num++;
	}
}

void enemy_move(int start)
{
	for (int i = 0 ; i < M ; i++)
		if(cp_map[N - 1][i])
			cp_enemy_num--;
	for (int i = N - 1; i > start ; i--)
		for (int j = 0 ; j < M ; j++)
			cp_map[i][j] = cp_map[i-1][j];
	for (int i = 0 ; i < M ; i++)
		cp_map[start][i] = 0;
}

void game_operation()
{
	int i = 0;

	cp_enemy_num = enemy_num;
	std::memcpy(cp_map, g_map, sizeof(g_map));
	kill_num = 0;
	while (cp_enemy_num)
	{
		archer_kill();
		enemy_move(i);
		i++;
	}
	if (kill_num > ans)
		ans = kill_num;
}

void combination(int ind, int depth)
{
	if (ind > M)
		return ;
	if (depth == 3)
	{
		game_operation();
		return ;
	}
	for (int i = ind ; i < M ; i++)
	{
		archor.push_back({N, i});
		combination(i + 1, depth + 1);
		archor.pop_back();
	}
}

void print_val()
{
	std::cout << ans;
}

void solve()
{
	combination(0, 0);
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}

