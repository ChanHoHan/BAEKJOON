//10799
#include <iostream>
#include <stack>

std::string inp;
std::stack <char> s;

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
}

void solve()
{
	int size = inp.size(), i = -1, ans = 0;

	while (++i < size)
	{
		if (inp[i] == '(')
			s.push(inp[i]);
		else
		{
			s.pop();
			if (inp[i - 1] == '(')
				ans += ((int)s.size());
			else
				ans++;
		}
	}
	std::cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}
