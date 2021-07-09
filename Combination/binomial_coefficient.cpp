//11050
#include <iostream>

int N, K;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> N >> K;
}

void solve()
{
	int up = 1, down = 1;

	for (int i = N ; i >= N - K + 1 ; i--)
		up *= i;
	for (int i = K ; i >= 2 ; i--)
		down *= i;
	std::cout << up / down;
}

int main()
{
	input();
	solve();
	return (0);
}
