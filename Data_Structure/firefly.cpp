#include <iostream>

int N, H, answer, count;
int sum[500010];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> N >> H;
	for (int i = 0 ; i < N ; i++)
	{
		int bar;
		std::cin >> bar;
		if (i & 1)
		{
			sum[H - bar + 1]++;
		}
		else
		{
			sum[1]++;
			sum[bar + 1]--;
		}
	}
}

void solve()
{
	answer = -1;

	for (int i = 1 ; i <= H ; i++)
	{
		sum[i] += sum[i - 1];
		if (answer == -1 || sum[i] < answer)
		{
			answer = sum[i];
			count = 1;
		}
		else if (sum[i] == answer)
			count++;
	}
	std::cout << answer << " " << count;
}

int main()
{
	input();
	solve();
	return (0);
}
