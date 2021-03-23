//2294
#include <iostream>
#include <vector>
#include <algorithm>

#define _MAX 10002
size_t n, k;
std::vector<int> coins;
std::vector<int> dp;


void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> n >> k;
	coins.resize(n);
	dp.resize(k + 1, _MAX);
	for (size_t i = 0 ; i < n ; i++)
		std::cin >> coins[i];
	std::sort(coins.begin(), coins.end());
}

void solve()
{
	size_t ind;

	for (size_t i = 0 ; i < n ; i++)
	{
		ind = coins[i];
		for (size_t j = ind; j <= k ; j++)
		{
			if (dp[j - ind] != _MAX)
				dp[j] = std::min(dp[j], dp[j - ind] + 1);
			else if (!(j % ind))
				dp[j] = j / ind;
		}
	}
}

void print_val()
{
	if (dp[k] != _MAX)
		std::cout << dp[k];
	else
		std::cout << -1;
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}

