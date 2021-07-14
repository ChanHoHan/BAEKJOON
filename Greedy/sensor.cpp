//2212
#include <iostream>
#include <algorithm>
int N, K;
int road[10001];
int interval[1001];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> N >> K;
	for (int i = 0 ; i < N ; i++)
		std::cin >> road[i];
}

bool compare(int a, int b)
{
	return (a > b);
}

void solve()
{
	int ans = 0;

	std::sort(road, road + N);
	if (N == 1)
	{
		std::cout << 0;
		return ;
	}
	for (int i = 1 ; i < N ; i++)
		interval[i - 1] = road[i] - road[i - 1];
	std::sort(interval, interval + N - 1, compare);
	for (int i = K - 1 ; i < N - 1 ; i++)
		ans += interval[i];
	std::cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}
