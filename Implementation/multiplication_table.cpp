#include <iostream>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
int N;

void input()
{
	FASTIO;
	cin >> N;
}

void solve()
{
	for (int i = 1 ; i <= 9 ; i++)
		cout << char(N + '0') << " * " << char(i + '0') << " = " << N * i << endl;
}

int main()
{
	input();
	solve();
	return (0);
}
