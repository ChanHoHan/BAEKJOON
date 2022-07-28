#include <iostream>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
int T;
int _data[17][17];

void input()
{
	FASTIO;
	cin >> T;
}

void solve()
{
	int k, n;
	for (int i = 1 ; i <= 15 ; i++)
		_data[0][i] = i;
	for (int i = 1 ; i < 15 ; i++)
		for (int j = 1 ; j <= 15 ; j++)
			_data[i][j] = _data[i - 1][j] + _data[i][j - 1];
	while (T--)
	{
		cin >> k >> n;
		cout << _data[k][n] << endl;
	}
}

int main()
{
	input();
	solve();
	return (0);
}
