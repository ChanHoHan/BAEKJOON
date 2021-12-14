#include <iostream>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
int A, B, reverse_A, reverse_B;

void input()
{
	FASTIO;
	cin >> A >> B;
	reverse_A = A / 100 + (A % 100) / 10 * 10 + A % 10 * 100;
	reverse_B = B / 100 + (B % 100) / 10 * 10 + B % 10 * 100;
}

void solve()
{
	int ans = reverse_A > reverse_B ? reverse_A : reverse_B;
	cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}
