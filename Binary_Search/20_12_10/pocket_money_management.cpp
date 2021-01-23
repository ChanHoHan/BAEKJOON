//6236
#include <iostream>

int N, M;
int pocket[100002];
int ans, val;

bool cal(int mid)
{
	val = 1;
	int h_money = mid;

	for(int i = 0 ; i < N; i++)
	{
		if (pocket[i] > h_money)
		{
			val ++;
			h_money = mid;
			if (pocket[i] > h_money)
				return (0);
		}
		h_money -= pocket[i];
	}
	if (val <= M)
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
	std::cout.tie(0);
	std::cin.tie(0);

	std::cin >> N >> M;
	for(int i = 0 ; i < N ; i++)
		std::cin >> pocket[i];
	int MAX = N * 10000;
	binary_search(1, MAX);
	std::cout << ans;

	return (0);
}
