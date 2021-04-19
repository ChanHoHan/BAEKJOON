//11501
#include <iostream>
#include <algorithm>
#define endl "\n"

int T, N;
int days[1000001];
int max_days[1000001];
int table[10001];
long long ans;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> T;
}

bool compare(int a, int b)
{
	return (a > b);
}

void solve()
{
	ans = 0;

	std::cin >> N;
	for (int i = 0 ; i < N ; i++)
	{
		std::cin >> days[i];
		max_days[i] = days[i];
		table[days[i]]++;
	}
	std::sort(max_days, max_days + N , compare);
	int max_val = max_days[0];
	int max_ind = 0;
	for (int i = 0 ; i < N ; i++)
	{
		table[days[i]]--;
		if (max_val > days[i])
			ans += (max_val - days[i]);
		else
		{
			while (++max_ind < N)
			{
				if (table[max_days[max_ind]])
				{
					max_val = max_days[max_ind];
					break;
				}
			}
		}
	}
	std::cout << ans << endl;
}

int main()
{
	input();
	while(T--)
		solve();
	return (0);
}
