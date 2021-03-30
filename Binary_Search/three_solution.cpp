//2473
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef long long ll;
std::vector<ll> sol;
ll ans[3];
ll max_val;
size_t N;

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
	sol.resize(N);
	for (size_t i = 0 ; i < N ; i++)
		std::cin >> sol[i];
	max_val = 999999999999999;
}

void solve()
{
	int _N, left, right;
	ll val;

	_N = N;
	std::sort(sol.begin(), sol.end());
	for (int i = 0 ; i < _N - 2 ; i++)
	{
		left = i + 1;
		right = _N - 1;
		while (true)
		{
			if (left == right)
				break;
			val = sol[i] + sol[left] + sol[right];
			if (std::abs(val) < std::abs(max_val))
			{
				max_val = val;
				ans[0] = sol[i];
				ans[1] = sol[left];
				ans[2] = sol[right];
			}
			if (val == 0)
				break;
			if (val < 0)
				left += 1;
			else
				right -= 1;
		}
	}
}

void print_val()
{
	std::sort(ans, ans+3);
	for (int i = 0  ; i < 3 ; i++)
		std::cout << ans[i] << " ";
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}
