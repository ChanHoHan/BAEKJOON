#include <iostream>
#include <algorithm>

int max_value;

long long	trees_section_sum(int height, int N, int *trees)
{
	long long result;

	result = 0;
	for (int i = (N - 1); i >= 0; i--)
	{
		if (trees[i] <= height)
			break;
		result += (trees[i] - height);
	}
	return (result);
}

void binary_search_result(int h_min, int h_max, int *trees, int N, int M)
{
	if (h_min > h_max)
		return;

	int h_mid = (h_min + h_max) / 2;
	long long sum_result = trees_section_sum(h_mid, N, trees);
	
	if (sum_result >= (long long)M)
	{
		if (max_value < h_mid)
			max_value = h_mid;
		if (sum_result == (long long)M || h_min == h_max)
			return;
		binary_search_result(h_mid + 1, h_max, trees, N, M);
	}
	else
		binary_search_result(h_min, h_mid - 1, trees, N, M);
}


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	max_value = 0;
	int N, M;
	int trees[1000000];

	std::cin >> N >> M;

	for(int i = 0; i < N ; i++)
		std::cin >> trees[i];
	std::sort(trees,trees + N);
	binary_search_result(0, trees[N - 1], trees, N, M);
	std::cout << max_value;
	return (0);
}
