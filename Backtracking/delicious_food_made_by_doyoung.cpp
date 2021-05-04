//2961
#include <iostream>
#include <algorithm>
#include <cmath>
int N;
long long ans = 1e10 + 1;

std::pair<int, int> taste[11];

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

void brute(int depth, int ind, long long bitter, long long sour, int &MAX)
{
	if (depth == MAX)
	{
		ans = std::min(ans, std::abs(bitter - sour));
		return ;
	}
	for (int i = ind ; i < N ; i++)
		brute(depth + 1, i + 1, bitter * taste[i].first, sour + taste[i].second, MAX);
}

void solve()
{
	for (int i = 1 ; i <= N ; i++)
		brute(0, 0, 1, 0, i);
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

