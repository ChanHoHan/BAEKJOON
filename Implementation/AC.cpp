//5430
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"
int T, n;
std::string p, arr;
int x[100001];
std::string ans;
int start, end, reverse;

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

bool is_num(char ch)
{
	if ('0' <= ch && ch <= '9')
		return (1);
	return (0);
}

void parsing()
{
	int i = 0;
	int size = arr.size();
	int save = 0;
	int x_ind = 0;

	while (++i < size)
	{
		if (is_num(arr[i]))
		{
			save *= 10;
			save += (arr[i] - '0');
		}
		else
		{
			x[x_ind++] = save;
			save = 0;
		}
	}
}

bool operation()
{
	start = 0;
	end = n - 1;
	reverse = 1;

	for (size_t i = 0 ; i < p.size() ; i++)
	{
		if (p[i] == 'R')
		{
			std::swap(start, end);
			reverse = -reverse;
		}
		else if (p[i] == 'D')
		{
			if (start * reverse > end * reverse)
			{
				ans = "error";
				return (0);
			}
			start += reverse;
		}
	}
	return (1);
}

void make_ans()
{
	ans = "[";

	if (reverse == 1)
		for (int i = start ; i <= end ; i++)
		{
			ans += std::to_string(x[i]);
			if (i < end)
				ans += ",";
		}
	else
		for (int i = start ; i >= end ; i--)
		{
			ans += std::to_string(x[i]);
			if (i > end)
				ans += ",";
		}
	ans += "]";
}

void solve()
{
	std::cin >> p >> n >> arr;
	parsing();
	if (!operation())
		return;
	make_ans();
}

void print_val()
{
	std::cout << ans << endl;
}

int main()
{
	input();
	while (T--)
	{
		solve();
		print_val();
	}
	return (0);
}
