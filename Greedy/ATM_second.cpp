//11399
#include <iostream>
#include <algorithm>

int N, P[1001];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> N;
	for (int i = 0 ; i < N ; i++)
		std::cin >> P[i];
}

void solve()
{
	std::sort(P, P + N);

	int val = P[0];
	for (int i = 1 ; i < N ; i++)
	{
		P[i] += P[i - 1];
		val += P[i];
	}
	std::cout<<val;
}

int main()
{
	input();
	solve();
	return (0);
}
