#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"

int N, M;
int arr[10], real_arr[10];
int real_index;

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
	for (int i = 0 ; i < N ; i++) std::cin >> arr[i];
}

void get_real_arr() 
{
	real_index = 1;

	real_arr[0] = arr[0];
	for (int i = 1 ; i < N ; i++) {
		if (arr[i] == arr[i - 1]) continue;
		real_arr[real_index++] = arr[i];
	}
}

void combination(int ind, std::vector<int> v)
{
	if ((int)v.size() == M)
	{
		for (auto& i: v) {
			std::cout << i << " ";
		}
		std::cout << endl;
		return;
	}
	for (int i = ind ; i < real_index ; i++) {
		v.push_back(real_arr[i]);
		combination(i, v);
		v.pop_back();
	}
}

void solve()
{
	std::sort(arr, arr + N);
	get_real_arr();
	combination(0, {});
}

int main()
{
	input();
	solve();
	return (0);
}
