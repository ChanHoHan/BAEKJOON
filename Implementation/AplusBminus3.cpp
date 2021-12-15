#include <iostream>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
int T, A, B;

void input()
{
	FASTIO;
	cin >> T;
}

void solve()
{
	for (int i = 0 ; i < T ; i++)
	{
		cin >> A >> B;
		cout << A + B << endl;
	}
}

int main()
{
	input();
	solve();
	return (0);
}
