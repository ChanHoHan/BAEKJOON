//11399
#include <iostream>
#include <vector>
#include <algorithm>

int N, ans;
std::vector<int> atm;

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
	atm.resize(N + 1);
	for (int i = 1 ; i <= N ; i++)
		std::cin >> atm[i];
}

void solve()
{
	std::sort(atm.begin(), atm.end());
	for (int i = 1 ; i <= N ; i++)
		atm[i] += atm[i - 1];
	for (int i = 1 ; i <= N ; i++)
		ans += atm[i];
}

void print_val()
{
	std::cout << ans;
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}
