//1406
#include <iostream>
#include <stack>

int M;
std::string str;
std::stack<char> s;
std::stack<char> save;

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
	std::cin >> M;
}

void cursor_moving(char command, char addition)
{
	if (command == 'L' && !s.empty())
	{
		save.push(s.top());
		s.pop();
	}
	else if (command == 'D' && !save.empty())
	{
		s.push(save.top());
		save.pop();
	}
	else if (command == 'B' && !s.empty())
		s.pop();
	else if (command == 'P')
		s.push(addition);
}

void solve()
{
	char command, addition;

	for (size_t i = 0 ; i < str.size(); i++)
		s.push(str[i]);
	while (M--)
	{
		std::cin >> command;
		if (command == 'P')
			std::cin >> addition;
		cursor_moving(command, addition);
	}
	while (!s.empty())
	{
		save.push(s.top());
		s.pop();
	}
}

void print_val()
{
	while (!save.empty())
	{
		std::cout << save.top();
		save.pop();
	}
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}

