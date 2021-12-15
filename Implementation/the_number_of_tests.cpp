#include <iostream>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"

int pow(int i)
{
	return i * i;
}

void solve()
{
	int ans = 0, N;

	for (int i = 0 ; i < 5 ; i++)
	{
		cin >> N;
		ans += pow(N);
	}
	cout << ans % 10;
}

int main()
{
	solve();
	return (0);
}
