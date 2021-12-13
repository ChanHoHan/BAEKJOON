#include <iostream>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
int A, B;

void input()
{
	FASTIO;
	cin >> A >> B;
}

void solve()
{
	if (A > B) cout << ">";
	else if (A < B) cout << "<";
	else if (A == B) cout << "==";
}

int main()
{
	input();
	solve();
	return (0);
}
