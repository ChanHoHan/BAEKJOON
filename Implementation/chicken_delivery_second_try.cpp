//15686
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

int N, M;
std::vector<std::pair<int, int> > c_houses;
std::queue<std::pair<int, int> >houses;
int c_size, h_size, min_dist = 99999999;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	int inp;

	io_faster();
	std::cin >> N >> M;
	for (int i = 1 ; i <= N ; i++)
		for (int j = 1 ; j <= N ; j++)
		{
			std::cin >> inp;
			if (inp == 2)
				c_houses.push_back({i, j});
			else if (inp == 1)
				houses.push({i, j});
		}
	c_size = c_houses.size();
	h_size = houses.size();
}

int check(int y, int x, std::vector<std::pair<int, int> >chick)
{
	int _min = 99999999, val;

	for (int i = 0 ; i < M ; i++)
	{
		val = std::abs(y - chick[i].first) + std::abs(x - chick[i].second);
		if (val < _min)
			_min = val;
	}
	return (_min);
}

void check_chicken_distance(std::vector<std::pair<int, int> >chick)
{
	int cnt = h_size;
	int y, x, dist = 0;

	while (cnt--)
	{
		y = houses.front().first;
		x = houses.front().second;
		houses.pop();
		dist += check(y, x, chick);
		houses.push({y, x});
	}
	if (min_dist > dist)
		min_dist = dist;
}

void brute_force(int index, int depth, std::vector<std::pair<int, int> >chick)
{
	if (depth == M)
	{
		check_chicken_distance(chick);
		return ;
	}
	if (index == c_size)
		return ;

	for (int i = index ; i < c_size ; i++)
	{
		chick.push_back({c_houses[i].first, c_houses[i].second});
		brute_force(i + 1, depth + 1, chick);
		chick.pop_back();
	}
}

void solve()
{
	brute_force(0, 0, {});
	std::cout << min_dist;
}

int main()
{
	input();
	solve();
	return (0);
}
