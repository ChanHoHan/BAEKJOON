//1292
#include <iostream>
#include <vector>

int A, B;
std::vector<int> arr;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> A >> B;

	int j;
	arr.push_back(1);
	for (int i = 2; i <= B ; i++)
	{
		j = i;
		while (j--)
			arr.push_back(arr.back() + i);
	}
}

void solve()
{
	if (A < 2)
		std::cout << arr[B - 1];
	else
		std::cout << arr[B - 1] - arr[A - 2];
}

int main()
{
	input();
	solve();
	return (0);
}
