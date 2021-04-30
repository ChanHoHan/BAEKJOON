//6236
#include <iostream>

int N, M, ans;
int pockets[100001];

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
		std::cin >> pockets[i];
}

int cal(int mid)
{
	int money = 0, cnt = 0;

	for (int i = 0 ; i < N ; i++)
	{
		if (mid < pockets[i])
			return (1e9 + 1);
		if (money - pockets[i] < 0)
		{
			money = mid;
			cnt++;
		}
		money -= pockets[i];
	}
	return (cnt);
}

void solve()
{
	int left = 0, right = 1e9, mid;

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (cal(mid) > M)
			left = mid + 1;
		else
			right = mid - 1;
	}
	ans = left;
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

