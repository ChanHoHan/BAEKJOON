//2512
#include <iostream>
#include <algorithm>

int N, M, MAX_, ans;
int request[10001];

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
	MAX_ = 0;
	for (int i = 0 ; i < N ; i++)
	{
		std::cin >> request[i];
		if (MAX_ < request[i])
			MAX_ = request[i];
	}
	std::cin >> M;
}

void solve()
{
	int left = 0, right = MAX_, mid, cnt;

	while (left <= right)
	{
		mid = (left + right) / 2;
		cnt = 0;
		for(int i = 0 ; i < N ; i++)
			cnt += std::min(mid, request[i]);
		if (cnt <= M)
			left = mid + 1;
		else
			right = mid - 1;
	}
	ans = right;
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

