//16922
#include <iostream>
#include <set>

int N;
std::set<int> s;
int num[4] = {1, 5, 10, 50};

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

void combination(int ind, int val, int depth)
{
	if (depth == N)
	{
		s.insert(val);
		return;
	}
	for (int i = ind ; i < 4 ; i++)
		combination(i, val + num[i], depth + 1);
}

void solve()
{
	combination(0, 0, 0);
}

void print_val()
{
	std::cout << s.size();
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}

