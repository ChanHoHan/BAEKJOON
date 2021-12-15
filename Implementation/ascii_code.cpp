#include <iostream>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
char x;

void input()
{
	FASTIO;
	cin >> x;
}

void solve()
{
	cout << (int) x;
}

int main()
{
	input();
	solve();
	return (0);
}
