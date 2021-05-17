//15654
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#define endl "\n"
int N, M;
int arr[9];

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
	for (int i = 0 ; i < N ; i++)
		std::cin >> arr[i];
	std::sort(arr, arr+N);
}

void brute_force(int depth, std::vector<int> a, std::unordered_set<int> b)
{
	if (depth == M)
	{
		for (size_t i = 0 ; i < a.size() ; i++)
			std::cout << a[i] << " ";
		std::cout << endl;
		return ;
	}
	for (int i = 0 ; i < N ; i++)
	{
		if (b.find(i) != b.end())
			continue;
		a.push_back(arr[i]);
		b.insert(i);
		brute_force(depth + 1, a, b);
		a.pop_back();
		b.erase(i);
	}
}

void solve()
{
	brute_force(0, std::vector<int>(), std::unordered_set<int> ());
}

int main()
{
	input();
	solve();
	return (0);
}
