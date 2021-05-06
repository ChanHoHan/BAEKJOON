//2529
#include <iostream>
#include <algorithm>
#include <string>
#define endl "\n"

int k;
char ineq[9];
bool visited[10];
long long g_max = 0, g_min = 1e10 + 1;
void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> k;
	for (int i = 0 ; i < k ; i++)
		std::cin >> ineq[i];
}

bool comp(int ind, int left, int right)
{
	if (ineq[ind] == '<')
		return (left < right);
	else
		return (left > right);
}

void brute(int ind, long long val)
{
	if (ind == k - 1)
	{
		for (int i = 0 ; i < 10 ; i++)
			if (!visited[i] && comp(ind, val % 10, i))
			{
				g_max = std::max(val * 10 + i, g_max);
				g_min = std::min(val * 10 + i, g_min);
			}
		return;
	}
	for (int i = 0 ; i < 10 ; i++)
	{
		if (visited[i])
			continue;
		if (ind == -1)
		{
			visited[i] = 1;
			brute(ind + 1, i);
			visited[i] = 0;
		}
		else
		{
			if (!comp(ind, val % 10, i))
				continue;
			visited[i] = 1;
			brute(ind + 1, val * 10 + i);
			visited[i] = 0;
		}
	}
}

void solve()
{
	brute(-1, 0);
}

void print_val()
{
	std::string ans_max;
	std::string ans_min;

	ans_max = std::to_string(g_max);
	ans_min = std::to_string(g_min);
	for (int i = 0 ; i <= k - (int)ans_max.size() ; i++)
		std::cout << '0';
	std::cout << ans_max << endl;
	for (int i = 0 ; i <= k - (int)ans_min.size() ; i++)
		std::cout << '0';
	std::cout << ans_min << endl;
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}
