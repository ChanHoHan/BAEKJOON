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
	for (int i = 0 ; i < N ; i++)
	{
		for (int j = 0 ; j < N - i - 1 ; j++)
			cout << " ";
		for (int j = 0 ; j <= i ; j++)
			cout << "*";
		cout << endl;
	}
}

int main()
{
	input();
	solve();
	return (0);
}
