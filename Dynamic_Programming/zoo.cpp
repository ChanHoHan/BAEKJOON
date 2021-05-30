//1309
#include <iostream>

int N;
int dp[100002];
std::pair<int, int> inp[100002];

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
}

void solve()
{
	inp[1].first = 1;
	inp[1].second = 1;
	dp[1] = 1;
	for (int i = 2 ; i < N + 1 ; i++)
	{
		inp[i].first = (inp[i - 1].second + dp[i - 1]) % 9901;
		inp[i].second = (inp[i - 1].first + dp[i - 1]) % 9901;
		dp[i] = (inp[i - 1].first + inp[i - 1].second + dp[i - 1]) % 9901;
	}
	std::cout << (inp[N].first + inp[N].second + dp[N]) % 9901;
}

int main()
{
	input();
	solve();
	return (0);
}
