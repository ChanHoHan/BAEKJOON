//2504
#include <iostream>

std::string str;
int ans, val, ind;

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> str;
}

int recursion()
{
	if (ind >= str.size())
		return (0);
	int now = str[ind];
	int val = 0;

	ind++;
	while (ind < str.size())
	{
		if (now == '(' && str[ind] == ')')
			return (val * 2 ? val * 2 : 2);
		else if (now == '[' && str[ind] == ']')
			return (val * 3 ? val * 3 : 3);
		val += recursion();
		ind++;
	}
	return (0);
}

void solve()
{
	ind = 0;
	int a;

	while (ind < str.size())
	{
		a = recursion();
		if (!a)
		{
			ans = 0;
			return ;
		}
		ans += a;
		ind++;
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

