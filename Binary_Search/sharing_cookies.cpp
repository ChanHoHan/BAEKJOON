//16401
#include <iostream>
int M, N, cookies[1000001];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> M >> N;
	for (int i = 0 ; i < N ; i++)
		std::cin >> cookies[i];
}

void solve()
{
	int left = 0, right = 1000000000, mid, cnt;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (mid == 0)
		{
			right = 0;
			break;
		}
		cnt = 0;
		for (int i = 0 ; i < N ; i++)
			cnt += cookies[i] / mid;
		if (cnt >= M)
			left = mid + 1;
		else
			right = mid - 1;
	}
	std::cout << right;
}

int main()
{
	input();
	solve();
	return (0);
}
