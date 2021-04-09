//16917
#include <iostream>

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
	ll c_val = 0, tmp, loop = (X + Y) * 2;

	ans = X * A + Y * B;
	while (c_val < loop)
	{
		if (X < 0)
			X = 0;
		if (Y < 0)
			Y = 0;
		tmp = X * A + Y * B + c_val * C;
		if (ans > tmp)
			ans = tmp;
		X--;
		Y--;
		c_val+=2;
	}
	std::cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}

