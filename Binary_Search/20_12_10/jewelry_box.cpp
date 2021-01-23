//2792
#include <iostream>

int N, M, ans;
int jewelry[300002];

bool cal(int mid)
{
	int val = 0;
	int quo, rem;

	for(int i = 0 ; i < M ; i++)
	{
		quo = jewelry[i] / mid;
		rem = jewelry[i] % mid;
		if (!rem)
			val += quo;
		else
			val += (quo + 1);
	}
	if (val <= N)
		return (1);
	return (0);
}

void binary_search(int min, int max)
{
	if (min > max)
		return ;
	int mid = (min + max) / 2;
	if (cal(mid))
	{
		ans = mid;
		binary_search(min, mid - 1);
	}
	else
		binary_search(mid + 1, max);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	std::cin >> N >> M;
	int MAX = 0;
	for(int i = 0 ; i < M ; i++)
	{
		std::cin >> jewelry[i];
		if (jewelry[i] > MAX)
			MAX = jewelry[i];
	}
	binary_search(1, MAX);
	std::cout << ans;
	return (0);
}
