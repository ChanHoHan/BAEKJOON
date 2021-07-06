//2805
#include <iostream>

int N, M;
int trees[1000001];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> N >> M;
	for (int i = 0 ; i < N ; i++)
		std::cin >> trees[i];
}

void solve()
{
	int left = 0, right = 2000000000, mid;
	long long val;

	while (left <= right)
	{
		mid = (left + right) / 2;
		val = 0;
		for (int i = 0 ; i < N ; i++)
			if (trees[i] > mid)
				val += (trees[i] - mid);
		if (val >= M)
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
