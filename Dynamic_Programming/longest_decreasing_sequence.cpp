//11722
#include <iostream>
#include <algorithm>

int N;
int A[1001];
int dp[1001];

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
		std::cin >> A[i];
}

int find_answer(int index)
{
	if (index == N - 1)
		return (1);
	if (dp[index])
		return (dp[index]);
	int cmp = A[index];
	for (int i = index + 1 ; i < N ; i++)
	{
		if (cmp > A[i])
			dp[index] = std::max(dp[index], find_answer(i) + 1);
	}
	if (dp[index] == 0)
		dp[index] = 1;
	return (dp[index]);
}

bool cmp(int a, int b)
{
	return (a > b);
}

void solve()
{
	if (N == 1)
	{
		std::cout << 1;
		return ;
	}
	for (int i = 0 ; i < N ; i++)
		find_answer(i);
	std::sort(dp, dp + N, cmp);
	std::cout << dp[0];
}

int main()
{
	input();
	solve();
	return (0);
}
