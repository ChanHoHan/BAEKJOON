//1110
#include <iostream>
#include <string>

std::string N;

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
	int i = 1;
	std::string a, b, c;

	if (N.size() < 2)
		N = "0" + N;
	b = N;
	while(true)
	{
		a = "";
		c = std::to_string((int)(b[0] - '0') + (int)(b[1] - '0'));
		a += b[1];
		a += c.back();
		if (a == N)
		{
			std::cout << i;
			break;
		}
		b = a;
		i++;
	}
}

int main()
{
	input();
	solve();
	return (0);
}
