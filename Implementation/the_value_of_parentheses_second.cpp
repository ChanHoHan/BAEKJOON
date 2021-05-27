//2504
#include <iostream>

std::string inp;
int ans, size;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> inp;
	size = inp.size();
}

char opposition(char ch)
{
	if (ch == ')')
		return '(';
	else if (ch == ']')
		return '[';
	return (0);
}

char error(char ch)
{
	if (ch == '(')
		return ']';
	else if (ch == '[')
		return ')';
	return (0);
}

int recursion(int &i)
{
	char val = inp[i];
	int cnt = 0, tmp;
	if (val == ')' || val == ']')
		return (0);
	while(++i < size)
	{
		if (val == opposition(inp[i]))
		{
			if (!cnt)
				cnt = 1;
			if (val == '(')
				return (cnt * 2);
			else if (val == '[')
				return (cnt * 3);
		}
		else if (error(val) == inp[i])
			return (0);
		else
		{
			tmp = recursion(i);
			if (!tmp)
				return (0);
			cnt += tmp;
		}
	}
	return (0);
}

void solve()
{
	int i = -1;
	int tmp;

	while(++i < size)
	{
		tmp = recursion(i);
		if (!tmp)
		{
			ans = 0;
			return ;
		}
		ans += tmp;
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
