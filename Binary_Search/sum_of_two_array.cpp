#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;

ll T, n, A[1001], m, B[1001];
std::vector<ll> n_A, n_B;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> T >> n;
	for (int i = 0 ; i < n ; i++)
		std::cin >> A[i];
	std::cin >> m;
	for (int i = 0 ; i < m ; i++)
		std::cin >> B[i];
	ll tmp_a, tmp_b;
	for (int i = 0 ; i < n ; i++)
	{
		tmp_a = 0;
		for (int j = i ; j < n ; j++)
		{
			tmp_a += A[j];
			n_A.push_back(tmp_a);
		}
	}
	for (int i = 0 ; i < m ; i++)
	{

		tmp_b = 0;
		for (int j = i ; j < m ; j++)
		{
			tmp_b += B[j];
			n_B.push_back(tmp_b);
		}
	}
	std::sort(n_B.begin(), n_B.end());
}

void solve()
{
	ll n_A_size = n_A.size(), find_val, ans = 0, upper,lower;
	
	for (int i = 0 ; i < n_A_size ; i++)
	{
		find_val = T - n_A[i];
		lower = std::lower_bound(n_B.begin(), n_B.end(), find_val) - n_B.begin();
		upper = std::upper_bound(n_B.begin(), n_B.end(), find_val) - n_B.begin();
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
