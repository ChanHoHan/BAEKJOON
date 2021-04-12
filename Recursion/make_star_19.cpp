//10994
#include <iostream>
#include <vector>
#define endl "\n";
int N;
std::vector<std::vector<char> >star;

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> N;
	star.resize(4 * N - 3 , std::vector<char>(4 * N - 3, ' '));
}

void recursion(int index, int range)
{
	if (range < 0)
		return ;
	for (int i = index ; i < index + range ; i++)
	{
		for (int j = index ; j < index + range ; j++)
		{
			if (i == index || i == index + range - 1)
				star[i][j] = '*';
			if (j == index || j == index + range - 1)
				star[i][j] = '*';
		}
	}
	recursion(index + 2, range - 4);
}

void solve()
{
	recursion(0, 4 * N -3);
}

void print_val()
{
	for (auto& i : star)
	{
		for (auto& j : i)
			std::cout << j;
		std::cout << endl;
	}
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}

