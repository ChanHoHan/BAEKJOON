//15664
#include <iostream>
#include <algorithm>
#define endl "\n"
int N, M;

int A[8], ans[8];
bool check[8];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> N >> M;
	for (int i = 0 ; i < N ; i++)
		std::cin >> A[i];
}

void recur(int k, int ind)
{
	if (k == M)
	{
		for (int i = 0 ; i < M ; i++)
			std::cout << ans[i] << " ";
		std::cout << endl;
	}
	int prev = 0;

	for (int i = ind ; i < N ; i++)
	{

		if (check[i])
			continue;
		if (prev != A[i])
		{
			check[i] = true;
			ans[k] = A[i];
			prev = A[i];
			recur(k + 1, i + 1);
			check[i] = false;
		}
	}
}

void solve()
{
	std::sort(A, A + N);
	recur(0, 0);
}

int main()
{
	input();
	solve();
	return (0);
}
