//2961
#include <iostream>
#include <algorithm>
#include <cmath>
#define endl "\n"
int N;
long long ans = 1e10 + 1;

std::pair<int, int> taste[11];
long long sour[11][300];
int index_[11];
int x;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> N;
	for (int i = 0 ; i < N ; i++)
		std::cin >> taste[i].first >> taste[i].second;
}

void make_sour(int depth, int ind, long long val, int &MAX)
{
	if (depth == MAX)
	{
		sour[depth][x++] = val;
		return ;
	}
	for (int i = ind ; i < N ; i++)
		make_sour(depth + 1, i + 1, val * taste[i].first, MAX);
}

void bitter(int depth, int ind, long long val, int &MAX)
{
	if (depth == MAX)
	{
		for (int i = 1 ; i <= N ; i++)
			for (int j = 0 ; j < index_[i] ; j++)
			{
				std::cout << sour[i][j]  << " " << val << " ";
				ans = std::min(std::abs(sour[i][j] - val), ans);
				std::cout << ans ;
			}
		return;
	}
	for (int i = ind ; i < N ; i++)
		bitter(depth + 1, i + 1, val + taste[i].second, MAX);
}

void solve()
{
	for (int i = 1 ; i <= N ; i++)
	{
		x = 0;
		make_sour(0, 0, 1, i);
		index_[i] = x;
	}
	/*
	for (int i = 1 ; i <= N ; i++)
	{
		for (int j = 0 ; j < index_[i] ; j++)
			std::cout << sour[i][j] << " ";
		std::cout << endl;
	}*/
	for (int i = 1 ; i <= N ; i++)
		bitter(0, 0, 0, i);
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

