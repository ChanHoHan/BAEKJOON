//15663
#include <iostream>
#include <algorithm>
#define endl "\n"

int N, M, a[8], answer[8];
bool used[8];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void recur(int k)
{
	if (k == M)
	{
		for (int i = 0 ; i < M ; i++)
			std::cout << answer[i] << " ";
		std::cout << endl;
		return ;
	}
	int prev = 0;
	for (int i = 0 ; i < N ; i++)
	{
		if (used[i])
			continue;
		if (prev != a[i])
		{
			used[i] = true;
			answer[k] = a[i];
			prev = a[i];
			recur(k + 1);
			used[i] = false;
		}
	}
}

void input()
{
	io_faster();
	std::cin >> N >> M;
	for (int i = 0 ; i < N ; i++)
		std::cin >> a[i];
	std::sort(a, a + N);
	recur(0);
}

void solve()
{

}

int main()
{
	input();
	solve();
	return (0);
}
