//11653
#include <iostream>
#include <vector>
#define endl "\n"
bool check[3201];
int N;
std::vector<int> prime;

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
}

void solve()
{
	for (int i = 2 ; i < 3200 ; i++)
	{
		if (check[i])
			continue;
		for (int j = i + i ; j < 3200 ; j+=i)
			check[j] = true;
	}
	if (N == 1)
		return;
	for (int i = 2 ; i < 3200 ; i++)
		if (!check[i])
			prime.push_back(i);
	for (int i = 0 ; i < prime.size() ; i++)
	{
		while (N % prime[i] == 0)
		{
			std::cout << prime[i] << endl;
			N /= prime[i];
		}
	}
	if (N > 1)
		std::cout << N;
}

int main()
{
	input();
	solve();
	return (0);
}
