//2096
#include <iostream>
#include <algorithm>
int N;

int max_table[2][3];
int min_table[2][3];

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
	int a, b, c, fl = 0;

	std::cin >> a >> b >> c;
	max_table[0][0] = a;
	max_table[0][1] = b;
	max_table[0][2] = c;
	min_table[0][0] = a;
	min_table[0][1] = b;
	min_table[0][2] = c;

	for (int i = 0 ; i < N - 1 ; i++)
	{
		fl = !fl;
		std::cin >> a >> b >> c;
		max_table[fl][0] = a;
		max_table[fl][1] = b;
		max_table[fl][2] = c;
		min_table[fl][0] = a;
		min_table[fl][1] = b;
		min_table[fl][2] = c;
		max_table[fl][0] += std::max(max_table[!fl][0], max_table[!fl][1]);
		max_table[fl][1] += std::max({max_table[!fl][0], max_table[!fl][1], max_table[!fl][2]});
		max_table[fl][2] += std::max(max_table[!fl][1], max_table[!fl][2]);
		min_table[fl][0] += std::min(min_table[!fl][0], min_table[!fl][1]);
		min_table[fl][1] += std::min({min_table[!fl][0], min_table[!fl][1], min_table[!fl][2]});
		min_table[fl][2] += std::min(min_table[!fl][1], min_table[!fl][2]);
	}
	std::cout << std::max({max_table[fl][0], max_table[fl][1], max_table[fl][2]}) << " " << std::min({min_table[fl][0], min_table[fl][1], min_table[fl][2]});
}

int main()
{
	input();
	solve();
	return (0);
}
