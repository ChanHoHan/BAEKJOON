//7453
#include <iostream>
#include <algorithm>
#include <vector>

int A[4001], B[4001], C[4001], D[4001], N;
std::vector<int> CD;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	int a,b,c,d,val;

	io_faster();
	std::cin >> N;
	for (int i = 0 ; i < N ; i++)
	{
		std::cin >> a >> b >> c >> d;
		A[i] = a;
		B[i] = b;
		C[i] = c;
		D[i] = d;
	}
	CD.reserve(16000001);
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < N ; j++)
		{
			val = C[i] + D[j];
			CD.push_back(val);
		}
	std::sort(CD.begin(), CD.end());
}

void solve()
{
	long long val, ans = 0, lower, upper;

	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < N ; j++)
		{
			val = -(A[i] + B[j]);
			lower = std::lower_bound(CD.begin(), CD.end(), val) - CD.begin();
			upper = std::upper_bound(CD.begin(), CD.end(), val)  - CD.begin();
			ans += (upper - lower);
		}
	std::cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}
