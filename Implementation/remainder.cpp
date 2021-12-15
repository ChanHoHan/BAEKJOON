#include <iostream>
#include <set>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
set<int> s;

void input()
{
	int n;

	FASTIO;
	for (int i = 0 ; i < 10 ; i++)
	{
		cin >> n;
		s.insert(n % 42);
	}
}

void solve()
{
	cout << s.size();
}

int main()
{
	input();
	solve();
	return (0);
}
