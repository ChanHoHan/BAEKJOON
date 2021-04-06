#include <iostream>
#include <string>
#define endl "\n"

std::string X;
int cnt;

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> X;
}

bool recursion(std::string x)
{
	if (x.size() < 2)
	{
		int y = x[0] - '0';
		if (!(y % 3))
			return (1);
		else
			return (0);
	}
	cnt++;
	int temp = 0;
	for (size_t i = 0 ; i < x.size(); i++)
		temp += x[i] - '0';
	return(recursion(std::to_string(temp)));
}

void solve()
{
	bool x = recursion(X);
	std::cout << cnt << endl;
	if(x)
		std::cout << "YES";
	else
		std::cout << "NO";
}

int main()
{
	input();
	solve();
	return (0);
}

