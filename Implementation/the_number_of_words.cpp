#include <iostream>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
string word;

void input()
{
	FASTIO;
	getline(cin, word);
}

void solve()
{
	size_t i = -1, flag = 0, ans = 0;

	while (++i <= word.size())
	{
		if (i == word.size() || (flag && word[i] == ' ')) {
			if (flag) ans++;
			flag = 0;
		}
		else if (!flag && word[i] != ' ') flag = 1;
	}
	cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}
