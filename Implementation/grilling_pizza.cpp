//1756
#include <iostream>
#include <algorithm>

int D, N;
const int maxN = 3e5 + 1;
int pizza[maxN], depth[maxN];

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> D >> N;
	for (int i = 0 ; i < D ; ++i)
		std::cin >> depth[i];
	for (int i = 0 ; i < N ; ++i)
		std::cin >> pizza[i];
}

void pre_set()
{
	int before = depth[0];

	for (int i = 1 ; i < D ; i++)
	{
		if (before < depth[i])
			depth[i] = before;
		else
			before = depth[i];
	}
}

void solve()
{
	int left = 0, right = D, mid, fl = 0;

	pre_set();
	for (int i = 0 ; i < N ; i++)
	{
		left = 0;
		right = right - 1;
		while(left <= right)
		{
			mid = (left + right) / 2;
			if (depth[mid] >= pizza[i])
				left = mid + 1;
			else
				right = mid - 1;
		}
	}
	right = right + 1;
	if (right < 0)
		std::cout << 0;
	else
		std::cout << right;
}

int main()
{
	input();
	solve();
	return (0);
}

