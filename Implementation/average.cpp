//1546
#include <iostream>

int N;
double score[1001];

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
	std::cout << std::fixed;
}

void solve()
{
	double val = 0, max_ = -1;

	for (int i = 0 ; i < N ; i++)
	{
		std::cin >> score[i];
		if (max_ < score[i])
			max_ = score[i];
	}
	for (int i = 0 ; i < N ; i++)
	{
		score[i] /= max_;
		score[i] *= 100;
	}
	for (int i = 0 ; i < N ; i++)
		val += score[i];
	std::cout.precision(3);
	std::cout << (val / N);
}

int main()
{
	input();
	solve();
	return (0);
}
