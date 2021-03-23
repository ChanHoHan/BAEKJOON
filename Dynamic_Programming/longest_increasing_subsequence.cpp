//11055
#include <iostream>
#include <vector>
#include <algorithm>

size_t N;
std::vector<int> arr;
std::vector<int> dp;
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
	std::cin >> N;
	arr.resize(N);
	dp.resize(N);
	for (size_t i = 0 ; i < N ; i++)
		std::cin >> arr[i];
}

int cal_max(int p_i, int val)
{
	int max_val = 0;

	if (p_i >= static_cast<int>(N))
		return (0);
	if (dp[p_i])
		return (dp[p_i]);
	for (size_t i = p_i + 1 ; i < N ; i++)
		if (arr[p_i] < arr[i])
			max_val = std::max(max_val, cal_max(i, arr[i]));
	dp[p_i] = max_val + val;
	return (max_val + val);
}

void solve()
{
	for (size_t i = 0 ; i < N ; i++)
		ans = std::max(ans, cal_max(i, arr[i]));
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

