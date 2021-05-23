//17609
#include <iostream>
#define endl "\n"

int T;

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

bool pseudo(int start, int end, int size, std::string &a)
{
	if (start == size)
		return (0);
	while(start < end)
	{
		if (a[start] != a[end])
			return (0);
		end--;
		start++;
	}
	return (1);
}

void solve()
{
	std::string a;

	std::cin >> a;

	int size = a.size();
	int start = 0;
	int end = size - 1;

	while (start < end)
	{
		if (a[start] != a[end])
		{
			if (!pseudo(start + 1 , end, size, a) && !pseudo(start, end - 1, size, a))
			{
				std::cout << 2 << endl;
				return ;
			}
			std::cout << 1 << endl;
			return ;
		}
		end--;
		start++;
	}
	std::cout << 0 << endl;
}

int main()
{
	input();
	while (T--)
		solve();
	return (0);
}
