#include <iostream>
#include <cmath>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"

int A, B;
bool prime[100001];

void input()
{
	FASTIO;
	cin >> A >> B;
}

void solve()
{
	for (int i = 2 ; i < 100001 ; i++) {
		if (!prime[i]) {
			for (int j = 2 ; j * i < 100001 ; j++) {
				prime[j * i] = true;
			}
		}
	}
	prime[1] = true;

	int ans = 0;
	for (int i = A ; i <= B ; i++) {
		int cnt = 0;
		int N = i;
		for (int j = 2 ; j <= sqrt(N) ; j++) {
			while(N % j == 0) {
				cnt++;
				N /= j;
			}
		}
		if (!prime[N]) cnt++;
		if (!prime[cnt])
			ans++;
	}
	cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}

