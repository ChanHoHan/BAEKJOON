//1802
#include <iostream>
#define endl "\n"

int T;
std::string info;

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


void recursion(int info_size)
{
	int start = info_size / 2;
	int i = 0;

	if (info_size == 1)
	{
		std::cout << "YES" << endl;
		return ;
	}
	while (info_size - 1 - i > start)
	{
		if (info[info_size - 1 - i] == info[i])
		{
			std::cout << "NO" << endl;
			return ;
		}
		i++;
	}
	recursion(start);
}

void solve()
{
	std::cin >> info;
	recursion(info.size());
}

int main()
{
	input();
	while(T--)
		solve();
	return (0);
}
