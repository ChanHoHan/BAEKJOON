//2512
#include <iostream>
#include <algorithm>

typedef long long ll;

int max_value;
int budgets_sum(int mid, int N, int *locals)
{
	int rtn = 0;

	for (int i = 0 ; i < N ; i++)
		rtn += (locals[i] <= mid) ? locals[i] : mid;
	return (rtn);
}

void binary_search(ll min, ll max, int N, int M, int *locals)
{
	if (min > max)
		return;
	ll mid = (min + max) / 2;
	if (mid == 0)
		mid = 1;
	int budgets_sum_val = budgets_sum(mid, N, locals);
	if (budgets_sum_val > M)
		binary_search(min, mid - 1, N, M, locals);
	else if (budgets_sum_val <= M)
	{
		if (max_value < mid)
			max_value = mid;
		binary_search(mid + 1, max, N, M, locals);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M;
	int locals[10000];

	std::cin >> N;
	for(int i = 0 ; i < N ; i++)
		std::cin >> locals[i];
	std::cin >> M;
	max_value = 0;

	std::sort(locals, locals + N);
	binary_search(0, locals[N - 1], N, M, locals);
	std::cout << max_value;
	return (0);
}
