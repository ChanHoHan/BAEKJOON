//10610
#include <iostream>

std::string N;

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
	int sum = 0, count[128] = {0,} , size = N.size();

	for (int i = 0 ; i < size ; i++)
	{
		sum += N[i] - '0';
		count[(int)N[i]]++;
	}
	if (sum % 3 != 0 || !count[(int)'0'])
	{
		std::cout << -1;
		return;
	}
	for (char i = '9' ; i >= '0' ; i--)
	{
		for (int j = 0 ; j < count[(int)i] ; j++)
			std::cout << i;
	}
}

int main()
{
	input();
	solve();
	return (0);
}
