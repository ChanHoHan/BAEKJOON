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
	string tmp;
	int ans = 0;

	cin >> tmp;
	for (size_t i = 0 ; i < tmp.size() ; i++)
	{
		ans += tmp[i] - '0';
	}
	cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}

