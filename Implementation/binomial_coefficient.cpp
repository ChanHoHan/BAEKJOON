#include <iostream>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
int N, K;

void input()
{
	FASTIO;
	cin >> N >> K;
}

int factorial(int v, int n)
{
	int r = 1;
	while(n)
		r *= v--, n--;
	return r;
}

void solve()
{
	cout << factorial(N, K) / factorial(K, K);
}

int main()
{
	input();
	solve();
	return (0);
}
