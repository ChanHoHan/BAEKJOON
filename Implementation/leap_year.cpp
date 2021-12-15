#include <iostream>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
int year;

void input()
{
	FASTIO;
	cin >> year;
}

bool check(int x)
{
	return (!(x % 4) && (x % 100 || !(x % 400)));
}

void solve()
{
	cout << check(year);
}

int main()
{
	input();
	solve();
	return (0);
}
