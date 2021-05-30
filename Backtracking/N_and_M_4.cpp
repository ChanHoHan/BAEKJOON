//15651
#include <iostream>
#include <vector>
#define endl "\n"

int N, M;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> N >> M;
}

void brute_force(int depth, int ind, std::vector<int> a)
{
	if (depth == M)
	{
		for (size_t i = 0 ; i < a.size() ; i++)
			std::cout << a[i] << " ";
		std::cout << endl;
		return ;
	}
	for (int i = ind ; i <= N ; i++)
	{
		a.push_back(i);
		brute_force(depth + 1, i, a);
		a.pop_back();
	}
}

void solve()
{
	brute_force(0, 1, std::vector<int>());
}

int main()
{
	input();
	solve();
	return (0);
}
