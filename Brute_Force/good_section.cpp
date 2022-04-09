#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"

int L, n;
int S[52];

void input()
{
	FASTIO;
	cin >> L;
	for (int i = 0 ; i < L ; i++) 
		cin >> S[i];
	cin >> n;

}

void solve()
{
	int left = 1, right = S[0], ans = 0;
	sort(S, S + L);
	for (int i = 0 ; i < L ; i++) {
		if (S[i] < n) left = S[i] + 1;
		else {
			right = S[i] - 1; break;
		}
	}
	if (left <= n && n <= right && left != right)
		ans = (n - left) * (right - n + 1) + (right - n);
	cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}
