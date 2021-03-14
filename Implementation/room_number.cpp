//1475
#include <iostream>

std::string N;
int ans;
char g_set[10];

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> N;
	ans = 0;
}

void increase_set()
{
	for(int i = 0 ; i < 10 ; i++)
		g_set[i]++;
	ans++;
}

void solve()
{
	increase_set();
	for (size_t i = 0 ; i < N.size() ; i++)
	{
		if (N[i] == '9' && !g_set[9])
		{
			if (!g_set[6])
			{
				increase_set();
				g_set[9]--;
			}
			else
				g_set[6]--;
		}
		else if (N[i] == '6' && !g_set[6])
		{
			if (!g_set[9])
			{
				increase_set();
				g_set[6]--;
			}
			else
				g_set[9]--;
		}
		else if (!g_set[N[i] - '0'])
		{
			increase_set();
			g_set[N[i] - '0']--;
		}
		else if (g_set[N[i] - '0'])
			g_set[N[i] - '0']--;
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

