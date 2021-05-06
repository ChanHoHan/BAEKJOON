//10866
#include <iostream>
#include <deque>
#define endl "\n"

int N;
std::deque<int> dq;

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
	int num;
	std::string op;

	while (N--)
	{
		std::cin >> op;
		if (op == "push_back")
		{
			std::cin >> num;
			dq.push_back(num);
		}
		else if (op == "push_front")
		{
			std::cin >> num;
			dq.push_front(num);
		}
		else if (op == "front")
		{
			if (dq.size())
				std::cout << dq.front() << endl;
			else
				std::cout << -1 << endl;
		}
		else if (op == "size")
		{
			std::cout << dq.size() << endl;
		}
		else if (op == "back")
		{
			if (dq.size())
				std::cout << dq.back() << endl;
			else
				std::cout << -1 << endl;
		}
		else if (op == "empty")
		{
			if (dq.size())
				std::cout << 0 << endl;
			else
				std::cout << 1 << endl;
		}
		else if (op == "pop_front")
		{
			if (dq.size())
			{
				std::cout << dq.front() << endl;
				dq.pop_front();
			}
			else
				std::cout << -1 << endl;
		}
		else if (op == "pop_back")
		{
			if (dq.size())
			{
				std::cout << dq.back() << endl;
				dq.pop_back();
			}
			else
				std::cout << -1 << endl;
		}
	}
}

int main()
{
	input();
	solve();
	return (0);
}

