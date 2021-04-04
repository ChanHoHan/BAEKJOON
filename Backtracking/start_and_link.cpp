//14889
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

int N;
int g_map[21][21];

std::vector<int> team;
std::vector<int> start_team;
std::vector<int> link_team;
std::vector<int> ind;

int ans;

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	int k = 1;
	input_faster();
	std::cin >> N;
	for (int i = 1 ; i <= N ; i++)
		for (int j = 1 ; j <= N ; j++)
			std::cin >> g_map[i][j];
	while (k <= N)
		team.push_back(k++);
	start_team.resize(N / 2);
	link_team.resize(N / 2);
	ans = 999999999;
	for (int i = 0 ; i < N / 2 ; i++)
		ind.push_back(0);
	for (int i = 0 ; i < N / 2 ; i++)
		ind.push_back(1);
}

int cal_team()
{
	int cnt = 0;

	for (size_t i = 0 ; i < start_team.size(); i++)
	{
		for (size_t j = 0 ; j < start_team.size(); j++)
		{
			if (i == j)
				continue;
			cnt+= g_map[start_team[i]][start_team[j]];
		}
	}

	for (size_t i = 0 ; i < link_team.size() ;i++)
	{
		for (size_t j = 0 ; j < link_team.size() ; j++)
		{
			if (i == j)
				continue;
			cnt -= g_map[link_team[i]][link_team[j]];
		}
	}

	return (std::abs(cnt));
}

void solve()
{
	int start_ind, link_ind, val;
	do
	{
		start_ind = 0;
		link_ind = 0;
		for (size_t i = 0 ; i < ind.size(); i++)
		{
			if (ind[i] == 1)
				start_team[start_ind++] = team[i];
			else
				link_team[link_ind++] = team[i];
		}
		val = cal_team();
		if (ans > val)
			ans = val;
	}while(std::next_permutation(ind.begin(), ind.end()));
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
