#include <iostream>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
int A, B, T;

void input()
{
	FASTIO;
	cin >> T;
}

// gcd(a, b) = gcd(b, r)
int lcm()
{
	int a = A, b = B;

	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return (A * B) / a;
}

void solve()
{
	while (T--)
	{
		cin >> A >> B;
		cout << lcm() << endl;
	}
}

int main()
{
	input();
	solve();
	return (0);
}
