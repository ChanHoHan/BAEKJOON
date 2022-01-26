#include <iostream>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
int a, b;

void input()
{
	FASTIO;
	cin >> a >> b;
}

int gcd(int x, int y) 
{
	int r = x % y;
	if (r == 0)
		return y;
	return gcd(y, r);
}

int lcm(int x, int y, int save)
{
	return (x * y / save);
}

void solve()
{
	int save = gcd(a, b);
	cout << save << endl;
	cout << lcm(a, b, save);
}

int main()
{
	input();
	solve();
	return (0);
}
