#include <iostream>
#include <algorithm>

int s_t[100001]; // 종유석
int s_b[100001]; // 석순

int N, H;
int *t_b;
int ans;

void binary_search(int min, int max, int height)
{
	if (min > max)
		return ;
	int mid = (min + max) / 2;
	if (t_b[mid] >=  height)
		binary_search(min, mid - 1, height);
	else
	{
		ans = mid + 1;
		binary_search(mid + 1, max, height);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int input;
	int number_in_height, shortest, tmp;
	int index1, index2;

	index1 = 0;
	index2 = 0;
	std::cin >> N >> H;
	for(int i = 0 ; i < N; i++)
	{
		std::cin >> input;
		if (!(i % 2))
			s_t[index1++] = input;
		else
			s_b[index2++] = input;
	}
	std::sort(s_t, s_t + (N / 2));
	std::sort(s_b, s_b + (N / 2));
	
	shortest = 100001;
	number_in_height = 0;
	for (int i = 1 ; i <= H ; i++)
	{
		ans = 0;
		tmp = 0;
		t_b = s_t;
		binary_search(0, N/2 - 1, H - i + 1);
		tmp += (N/2 - ans);
		t_b = s_b;
		ans = 0;
		binary_search(0, N/2 - 1, i);
		tmp += (N/2 - ans);
		if (tmp < shortest)
		{
			shortest = tmp;
			number_in_height = 1;
		}
		else if (tmp == shortest)
			number_in_height += 1;
	}

	std::cout << shortest << " " << number_in_height;
	return (0);
}

