//15686
#include <iostream>
#include <vector>
#include <cmath>

#define endl "\n"

int N, M;
int g_map[51][51];
std::vector<std::pair<int, int> >chickens;
std::vector<std::pair<int, int> >cities;
int ans = 999999999;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> N >> M;
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < N ; j++)
		{
			std::cin >> g_map[i][j];
			if (g_map[i][j] == 1)
				cities.push_back({i, j});
			if (g_map[i][j] == 2)
				chickens.push_back({i, j});
		}
}

void check(std::vector<int> chicken_houses)
{
	int c_size = cities.size();
	int c_y, c_x, y, x, val = 0, max_val, tmp;

	for (int i = 0 ; i < c_size ; i++)
	{
		max_val = 999999999;
		c_y = cities[i].first;
		c_x = cities[i].second;
		for (int j = 0 ; j < M ; j++)
		{
			y = chickens[chicken_houses[j]].first;
			x = chickens[chicken_houses[j]].second;
			tmp = std::abs(c_y - y) + std::abs(c_x - x);
			if (tmp < max_val)
				max_val = tmp;
		}
		val += max_val;
	}
	if (val < ans)
		ans = val;
}

void brute_force(int index, int depth, std::vector<int> chicken_houses)
{
	if (depth == M)
		check(chicken_houses);
	int size = chickens.size();
	for (int i = index ; i < size ; i++)
	{
		chicken_houses.push_back(i);
		brute_force(i + 1, depth + 1, chicken_houses);
		chicken_houses.pop_back();
	}
}

void solve()
{
	brute_force(0, 0, std::vector<int> ());
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
