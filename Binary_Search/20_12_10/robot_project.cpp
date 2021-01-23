//3649
#include <iostream>
#include <algorithm>
#define endl "\n"
int x, n, MAX, to_find, MIN, MAX_diff, ans;
int lego[1000002];
void binary_search(int min, int max)
{
	if (min > max)
		return ;
	int mid = (min + max) / 2;
	if (to_find >= lego[mid])
	{
		if (to_find == lego[mid])
			ans = lego[mid];
		binary_search(mid + 1, max);
	}
	else
		binary_search(min, mid - 1);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	while(std::cin >> x >> n)
	{
		x *= 10000000; // 나노미터 변환
		for(int i = 0 ; i < n ; i++)
			std::cin >> lego[i];
		std::sort(lego, lego + n);
		MAX = 0;
		MAX_diff = -1;
		for(int i = 0 ; i < n - 1 ; i++)
		{
			to_find = x - lego[i];
			ans = 0;
			binary_search(i+1, n - 1);
			if (MAX_diff < ans - lego[i])
			{
				MAX = ans;
				MIN = lego[i];
				MAX_diff = ans - lego[i];
			}
		}
		if (MAX)
			std::cout << "yes " << MIN << " " <<MAX << endl;
		else
			std::cout << "danger" << endl;
	}
	return (0);
}
		
