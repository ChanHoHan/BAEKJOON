//1024
#include <iostream>
#define MAX_ 1000000000
typedef long long ll;
int N, L, ans;

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> N >> L;
	ans = -1;
}

void binary_search(int b_min, int b_max, int length)
{
	ll val = 0;

	if (b_min > b_max)
		return ;
	int b_mid = (b_min + b_max) / 2;
	for (int i = 0 ; i < length ; i++)
		val += (b_mid + i);
	if (val == N)
	{
		ans = b_mid;
		for (int i = 0 ; i < length ; i++)
		{
			std::cout << b_mid + i << " ";
		}
		return ;
	}
	if (val < N)
		binary_search(b_mid + 1, b_max, length);
	else
		binary_search(b_min, b_mid - 1, length);
}

void solve()
{
	int i = L - 1;

	while (++i <= 100 && (ans == -1))
		binary_search(0, MAX_, i);
	if (ans == -1)
		std::cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}

