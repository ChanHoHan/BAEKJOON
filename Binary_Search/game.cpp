//1072
#include <iostream>

long long X, Y;
void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> X >> Y;
}

void solve()
{
	long long init = (Y * 100) / X;
	if (init >= 99)
	{
		std::cout << -1;
		return ;
	}
	long long start = 0, end = 1000000000, mid;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (init < ((Y + mid) * 100) / (X + mid))
			end = mid - 1;
		else
			start = mid + 1;
	}
	std::cout << start;
}

int main()
{
	input();
	solve();
	return (0);
}
