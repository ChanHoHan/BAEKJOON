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

int mult(int v, int n)
{
	int r = 1;
	while(n)
		r *= v--, n--;
	return r;
}

void solve()
{
	cout << mult(N, K) / mult(K, K);
}

int main()
{
	input();
	solve();
	return (0);
}
