#include <iostream>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
string S;
int T;

void input()
{
	FASTIO;
	cin >> T;
}

void solve()
{
	int R;
	string S;
	size_t i;

	while (T--)
	{
		i = -1;
		cin >> R >> S;
		while (++i < S.size())
			for (int j = 0 ; j < R ; j++)
				cout << S[i];
		cout << endl;
	}
}

int main()
{
	input();
	solve();
	return (0);
}
