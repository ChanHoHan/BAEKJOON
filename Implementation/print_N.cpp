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
	for (int i = 1 ; i <= N ; i++)
		cout << i << endl;
}

int main()
{
	input();
	solve();
	return (0);
}
