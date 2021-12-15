#include <iostream>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
string S;
int table[27];

void input()
{
	FASTIO;
	cin >> S;
}

void solve()
{
	for (int i = 0 ; i < 26 ; i++)
		table[i] = -1;
	for (size_t i = 0 ; i < S.size() ; i++)
	{
		if (table[S[i] - 'a'] == -1)
			table[S[i] - 'a'] = i;
	}
	for (int i = 0 ; i < 26 ; i++) 
	{
		cout << table[i] << " " ;
	}
}

int main()
{
	input();
	solve();
	return (0);
}

