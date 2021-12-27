#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"

int N;
pair<int, int> arr[1010];
int dp[1010];

void input()
{
	FASTIO;
	cin >> N;
	for (int i = 0 ; i < N ; i++)
		cin >> arr[i].first >> arr[i].second;
}

void solve()
{
	int ans = 0;
	for (int i = 0 ; i < N ; i++)
	{
		int T = arr[i].first, P = arr[i].second;
		if (i >= 1)
			dp[i] = max(dp[i], dp[i - 1]);
		if (T + i <= N) 
		{
			dp[T + i] = max(dp[T + i], dp[i] + P);
			if (ans < dp[T + i])
				ans = dp[T + i];
		}
		if (ans < dp[i])
			ans = dp[i];
	}
	cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}

