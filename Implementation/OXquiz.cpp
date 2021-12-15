#include <iostream>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
int T;

void input()
{
	FASTIO;
	cin >> T;
}

void solve()
{
	string t;
	int flag, ans;

	for (int i = 0 ; i < T ; i++)
	{
		cin >> t;
		flag = 0;
		ans = 0;
		for (size_t j = 0 ; j < t.size() ; j++)
		{
			if (t[j] == 'O')
				ans += ++flag;
			else
				flag = 0;
		}
		cout << ans << endl;
	}
}

int main()
{
	input();
	solve();
	return (0);
}

