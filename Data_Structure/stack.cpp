//10828
#include <iostream>
#include <string>
#include <stack>
#define endl "\n"
int N;

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
}

void solve()
{
	std::string op;
	std::stack<int> s;
	int n;

	while (N--)
	{
		std::cin >> op;
		if (op == "push")
		{
			std::cin >> n;
			s.push(n);
			continue;
		}
		else if (op == "pop")
		{
			if (s.empty())
				std::cout << -1;
			else
			{
				std::cout << s.top();
				s.pop();
			}
		}
		else if (op == "size")
			std::cout << s.size();
		else if (op == "empty")
			std::cout << s.empty();
		else if (op == "top")
		{
			if (s.empty())
				std::cout << -1;
			else
				std::cout << s.top();
		}
		std::cout << endl;
	}
}

int main()
{
	input();
	solve();
	return (0);
}

