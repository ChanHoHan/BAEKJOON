//1920
#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
int N;
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
	std::cin >> N;
	arr.resize(N);
	for (int i = 0 ; i < N ; i++)
		std::cin >> arr[i];
	std::sort(arr.begin(), arr.end());
}

void b_search(int inp)
{
	int left = 0, right = N - 1, mid;

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr[mid] == inp)
		{
			std::cout << 1;
			return ;
		}
		if (arr[mid] < inp)
			left = mid + 1;
		else
			right = mid - 1;
	}
	std::cout << 0;
}

void solve()
{
	int n, inp;
	std::cin >> n;
	for (int i = 0 ; i < n ; i++)
	{
		std::cin >> inp;
		b_search(inp);
		std::cout << endl;
	}
}

int main()
{
	input();
	solve();
	return (0);
}
