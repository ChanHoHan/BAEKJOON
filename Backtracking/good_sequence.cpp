//2661
#include <iostream>
#include <string>

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

bool check(std::string val)
{
	int val_size = val.size();
	int cnt;

	for (int i = 1 ; i <= val_size / 2 ; i++)
	{
		cnt = 0;
		for (int j = val_size - 1 ; j >= val_size - i ; j--)
			if (val[j] == val [j - i])
				cnt++;
		if (cnt == i)
			return (0);
	}
	return (1);
}

bool recursion(int depth, std::string prev_val)
{
	std::string next;

	if (depth == N)
	{
		std::cout << prev_val;
		return (1);
	}
	for (int i = 1 ; i <= 3 ; i++)
	{
		next = prev_val + (char)(i + '0');
		if(!check(next))
			continue;
		if(recursion(depth + 1, next))
			return (1);
	}
	return (0);
}

void solve()
{
	recursion(0, "");
}

int main()
{
	input();
	solve();
	return (0);
}
