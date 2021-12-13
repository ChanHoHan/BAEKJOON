#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"

string word;
pair<int, int> table[30];

void input()
{
	FASTIO;
	cin >> word;
}

bool compare(pair<int, int>a, pair<int, int>b)
{
	return (a.second > b.second);
}

void solve()
{
	for (int i = 0 ; i < 30 ; i++)
		table[i].first = i;
	for (size_t i = 0 ; i < word.size() ; i++)
	{
		if (word[i] <= 'Z')
			table[word[i] - 'A'].second++;
		else
			table[word[i] - 'a'].second++;
	}
	sort(table, table + 30, compare);
	if (table[0].second == table[1].second) cout << "?";
	else cout << char('A' + table[0].first);
}

int main()
{
	input();
	solve();
	return (0);
}

