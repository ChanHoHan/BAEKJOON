//2003
#include <iostream>

int N, M;
int A[10002];
int ans;

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();

	std::cin >> N >> M;
	for (int i = 0 ; i < N ; i++)
		std::cin >> A[i];
}

void solve()
{
	int left, right;

	left = 0;
	right = 0;
	int sum_val = A[0];
	while (right != N)
	{
		if (sum_val == M)
			ans++;
		if (sum_val > M)
		{
			sum_val -= A[left];
			left+=1;
		}
		else
		{
			right+=1;
			sum_val += A[right];
		}
	}
}

void print_val()
{
	std::cout << ans;
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}

