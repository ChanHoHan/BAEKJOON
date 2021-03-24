//5582
#include <iostream>
#include <algorithm>
#include <vector>

std::string A, A_tmp;
std::string B, B_tmp;

int ans;
std::vector<std::vector<int> >dp;

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> A_tmp >> B_tmp;
	A = "*";// padding
	B = "(";// pading
	A += A_tmp;
	B += B_tmp;
	ans = 0;
	dp.resize(A.size() + 1, std::vector<int>(B.size() + 1));
}

void solve()
{
	for (size_t i = 1 ; i < A.size() ; i++)
	{
		for (size_t j = 1 ; j < B.size(); j++)
		{
			if (A[i] == B[j])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				ans = std::max(ans, dp[i][j]);
			}
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
