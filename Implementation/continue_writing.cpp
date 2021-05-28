//1790
#include <iostream>
#include <string>
#include <cmath>

int N, k;
long long table[11];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> N >> k;

	table[1] = 9;
	for (int i = 2 ; i < 10 ; i++)
		table[i] = table[i - 1] + i * std::pow(10, i - 1) * 9;

}

void solve()
{
	int ind,number, number_ind;//ind : 자리수, number : 몇번째

	for (int i = 1 ; i < 10 ; i++)
	{
		ind = i;
		if (k <= table[i])
			break;
	}
	number = std::pow(10, (ind - 1)) + (int)((k - table[ind - 1] - 1) / ind);
	number_ind = (int)(k - table[ind - 1] - 1) % ind;
	if (number > N)
	{
		std::cout << -1;
		return ;
	}
	std::cout << std::to_string(number)[number_ind];
}

int main()
{
	input();
	solve();
	return (0);
}

