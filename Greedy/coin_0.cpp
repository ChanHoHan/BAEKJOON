//11047
#include <iostream>
#include <vector>

int N, K, ans;
std::vector<int> A;

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> N >> K;
	A.resize(N);
	for (int i = 0 ; i < N ; i++)
		std::cin >> A[i];
}

void solve()
{
	for (int i = N - 1 ; K != 0 && i >= 0 ; i--)
	{
		if (A[i] <= K)
		{
			ans += (K / A[i]);
			K %= A[i];
		}
	}
}

void print_val()
{
	std::cout << ans;
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}

