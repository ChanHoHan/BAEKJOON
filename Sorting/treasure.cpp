//1026
#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
int N;
std::vector<int> A;
std::vector<int> B;

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
	A.resize(N);
	B.resize(N);
	for (int i = 0 ; i < N ; i++)
		std::cin >> A[i];
	for (int i = 0 ; i < N ; i++)
		std::cin >> B[i];
}

bool compare(int a, int b)
{
	return (a > b);
}

void solve()
{
	int ans = 0;

	std::sort(A.begin(), A.end());
	std::sort(B.begin(), B.end(), compare);
	for (int i = 0 ; i < N ; i++)
		ans += (A[i] * B[i]);
	std::cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}
