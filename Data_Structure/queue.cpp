//10845
#include <iostream>
#define endl "\n"

int N;
int queue[10002];
std::string op;

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

bool is_empty(int a, int b)
{
	return a == b;
}

void solve()
{
	int front = 0, back = 0, val;

	while (N--)
	{
		std::cin >> op;
		if (op == "push")
		{
			std::cin >> val;
			queue[back++] = val;
		}
		else if (op == "front")
		{
			if (is_empty(front, back))
				std::cout << -1 << endl;
			else
				std::cout << queue[front] << endl;
		}
		else if (op == "back")
		{
			if (is_empty(front, back))
				std::cout << -1 << endl;
			else
				std::cout << queue[back - 1] << endl;
		}
		else if (op == "size")
			std::cout << back - front << endl;
		else if (op == "pop")
		{
			if (is_empty(front, back))
				std::cout << -1 << endl;
			else
				std::cout << queue[front++] << endl;
		}
		else if (op == "empty")
			std::cout << is_empty(front, back) << endl;
	}
}

int main()
{
	input();
	solve();
	return (0);
}

