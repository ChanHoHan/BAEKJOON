//1269
#include <iostream>
#include <vector>
#include <unordered_set>

int a, b;
std::vector<int> B;
std::unordered_set<int> A_set;

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	int tmp;

	input_faster();
	std::cin >> a >> b;
	B.resize(b);
	for (int i = 0 ; i < a ; i++)
	{
		std::cin >> tmp;
		A_set.insert(tmp);
	}
	for (int j = 0 ; j < b ; j++)
		std::cin >> B[j];
}

void solve()
{
	for (const auto& i : B)
	{
		if (A_set.erase(i))
			b--;
	}
}

void print_val()
{
	std::cout << static_cast<int>(A_set.size()) + b;
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}
