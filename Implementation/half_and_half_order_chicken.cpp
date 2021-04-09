//16917
#include <iostream>
#include <algorithm>

typedef long long ll;

ll A, B, C, X, Y, ans;

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> A >> B >> C >> X >> Y;
}

void solve()
{
	ll c_num = 0, tmp, loop = std::max(X, Y) * 2;

	ans = X * A + Y * B;
	while (c_num <= loop)
	{
		tmp = X * A + Y * B + c_num * C;
		if (ans > tmp)
			ans = tmp;
		if (X > 0)
			X--;
		if (Y > 0)
			Y--;
		c_num += 2;
	}
	std::cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}

