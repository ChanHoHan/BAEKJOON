//1735
#include <iostream>

int a, b, c, d, p, q;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return (gcd(b, a % b));
}

void input()
{
	io_faster();
	std::cin >> a >> b >> c >> d;
	p = a * d + b * c;
	q = b * d;
}

void solve()
{
	int g = gcd(p, q);
	std::cout << p / g << " " << q / g;
}

int main()
{
	input();
	solve();
	return (0);
}
