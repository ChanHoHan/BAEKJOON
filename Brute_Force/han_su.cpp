#include <iostream>
#include <string>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
int N;

void input()
{
	FASTIO;
	cin >> N;
}

bool is_hansu(string s)
{
	int n = s.size();

	if (n <= 2) return true;
	int v = s[1] - s[0];

	for (int i = 2 ; i < n ; i++)
		if (s[i] - s[i - 1] != v) return false;
	return true;
}

void solve()
{
	int ans = 0;

	for (int i = 1 ; i <= N ; i++) {
		ans += is_hansu(to_string(i));
	}
	cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}
