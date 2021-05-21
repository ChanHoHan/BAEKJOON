//2502
#include <iostream>
#define endl "\n"
#define MAX 100000;

int A, B, D, K;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> D >> K;
}

int cal(int first, int second, int ind)
{
	if (ind == D)
		return (first + second);
	return (cal(second, first + second, ind + 1));
}

void solve()
{
	int start, end, mid, val;

	for (int i = 0 ; i <= 100000 ; i++)
	{
		start = i;
		end = MAX;
		while (start <= end)
		{
			mid = (start + end) / 2;
			val = cal(i, mid, 3);
			if (val == K)
			{
				A = i;
				B = mid;
				return ;
			}
			if (val > K)
				end = mid - 1;
			else
				start = mid + 1;
		}
	}
}

void print_val()
{
	std::cout << A << endl << B;
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}
