//2003
#include <iostream>
int N, M;
int A[10001];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> N >> M;
	for (int i = 0 ; i < N ; i++)
		std::cin >> A[i];
}

void solve()
{
	int start = 0;
	int end = 0;
	int val = A[start];
	int ans = 0;

	while (end < N)
	{
		if (val <= M)
		{
			if (val == M)
				ans++;
			if (end == N - 1)
				break;
			end++;
			val += A[end];
		}
		else
		{
			val -= A[start];
			start++;
		}
		if (start > end)
		{
			end = start;
			val = A[start];
		}
	}
	std::cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}
