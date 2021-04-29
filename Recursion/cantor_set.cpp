//4779
#include <iostream>
#include <cmath>
#define endl "\n"

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void recursion(int n)
{
	if (n == 1)
	{
		std::cout << "-";
		return;
	}
	recursion(n / 3);
	for (int i = 0 ; i < n / 3 ; i++)
		std::cout << " ";
	recursion(n / 3);
}

void solve(int N)
{
	recursion(std::pow(3, N));
}

int main()
{
	int N;

	while (std::cin >> N)
	{
		solve(N);
		std::cout << endl;
	}
	return (0);
}
