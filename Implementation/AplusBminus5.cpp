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
	while (true)
	{
		cin >> A >> B;
		if (A == 0 && B == 0)
			break;
		cout << A + B << endl;
	}
}

int main()
{
	input();
	solve();
	return (0);
}
