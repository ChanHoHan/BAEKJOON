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

int ans(int n)
{
	int i = 0;

	while (true)
	{
		i++;
		if (3 * i * i - 3 * i + 2 > n )
			break;
	}
	return i;
}

void solve()
{
	cout << ans(N);
}

int main()
{
	input();
	solve();
	return (0);
}

