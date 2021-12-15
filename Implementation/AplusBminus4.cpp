#include <iostream>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
int A, B;

void input()
{
	FASTIO;
}

void solve()
{
	while (cin >> A >> B)
	{
		cout << A + B << endl;
	}
}

int main()
{
	input();
	solve();
	return (0);
}
