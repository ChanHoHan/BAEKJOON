#include <iostream>
#include <cmath>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
int N;

void input()
{
	FASTIO;
	cin >> N;
}

int is_prime(int num)
{
	if (num == 1) return 0;
	if (num % 2 == 0) return num == 2 ? 1 : 0;
	int sqrt_num = sqrt(num);
	for (int i = 3 ; i <= sqrt_num ; i+=2)
		if (!(num % i)) return 0;
	return 1;
}

void solve()
{
	int tmp, ans = 0;

	for (int i = 0 ; i < N ; i++)
	{
		cin >> tmp;
		ans += is_prime(tmp);
	}
	cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}
