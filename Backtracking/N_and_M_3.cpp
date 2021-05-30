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

void brute_force(int depth, std::vector<int>& a)
{
	if (depth == M)
	{
		for (size_t i = 0 ; i < a.size() ; i++)
			std::cout << a[i] << " ";
		std::cout << endl;
		return ;
	}
	for (int i = 1 ; i <= N ; i++)
	{
		a.push_back(i);
		brute_force(depth + 1, a);
		a.pop_back();
	}
}

void solve()
{
	std::vector<int> a;
	brute_force(0, a);
}

int main()
{
	input();
	solve();
	return (0);
}
