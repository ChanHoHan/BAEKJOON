//14476
#include <iostream>
#define endl "\n"
int N;
int left_gcd[1000001];
int right_gcd[1000001];
int A[1000001];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> N;
	for (int i = 1 ; i <= N ; i++)
		std::cin >> A[i];
}

int gcd(int a, int b)
{
	if (b == 0)
		return (a);
	return (gcd(b, a % b));
}

void solve()
{
	int ans = -1, val = 0;

	for (int i = 1 ; i <= N ; i++)
		left_gcd[i] = gcd(left_gcd[i - 1], A[i]);
	for (int i = N ; i >= 1 ; i--)
		right_gcd[i] = gcd(right_gcd[i + 1], A[i]);
	for (int i = 1 ; i <= N ; i++)
	{
		int cur_gcd = gcd(left_gcd[i - 1], right_gcd[i + 1]);
		if (A[i] % cur_gcd == 0)
			continue;
		if (ans < cur_gcd)
		{
			ans = cur_gcd;
			val = A[i];
		}
	}
	if (ans != -1)
		std::cout << ans << " " << val;
	else
		std::cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}
