//1806
#include <iostream>

int N, S;
int seq[100001];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> N >> S;
	for (int i = 0 ; i < N ; i++)
		std::cin >> seq[i];
}

void solve()
{
	int s = 0, e = 0, val = seq[0], min_len = 100001;

	while (e < N)
	{
		if (val >= S)
		{
			if (min_len > (e - s + 1))
				min_len = e - s + 1;
			val -= seq[s];
			s++;
		}
		else
		{
			if (e == N - 1)
				break;
			e++;
			val += seq[e];
		}
		if (s > e)
		{
			val =seq[s];
			e = s;
		}
	}
	if (min_len == 100001)
		min_len = 0;
	std::cout << min_len;
}

int main()
{
	input();
	solve();
	return (0);
}
