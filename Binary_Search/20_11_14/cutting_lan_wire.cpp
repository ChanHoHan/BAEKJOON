//1654
#include <iostream>
#include <algorithm>
typedef long long ll;

int max_value;
ll MAXIMUM;
ll len_of_wires(int *wires, int mid, int K)
{
	ll return_val = 0;

	for (int i = 0 ; i < K ; i++)
		return_val += wires[i] / mid;
	return (return_val);
}

void binary_search(ll min, ll max, int K, int N, int *wires)
{
	if (min > max || max >= MAXIMUM)
		return ;
	ll mid = (min + max) / 2;
	if (mid == 0)
		mid = 1;
	ll the_number_of_cutted_wires = len_of_wires(wires, mid, K);

	if (the_number_of_cutted_wires < (ll)N) //더 짧게 짤라야 하므로
		binary_search(min, mid - 1, K, N, wires);
	else if (the_number_of_cutted_wires >= (ll)N)
	{
		if (max_value < mid)
			max_value = mid;
		binary_search(mid + 1, max, K, N, wires);
	}
}


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int K, N;
	int wires[10000];
	MAXIMUM = 1;
	MAXIMUM = MAXIMUM << 31;

	std::cin >> K >> N;
	for(int i = 0 ; i < K; i++)
		std::cin >> wires[i];
	std::sort(wires, wires + K);
	max_value = 0;
	binary_search(0, wires[K - 1], K, N, wires);
	std::cout << max_value;

	return (0);
}
