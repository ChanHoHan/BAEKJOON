//1958
#include <iostream>
#include <algorithm>

std::string a,b,c;
int dp[101][101][101];

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> a >> b >> c;
}

void solve()
{
	for (int i = 1 ; i <= a.size(); i++)
	{
		for (int j = 1 ; j <= b.size(); j++)
		{
			for (int k = 1 ; k <= c.size(); k++)
			{
				if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1])
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				else
					dp[i][j][k] = std::max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
			}
		}
	}
}

void print_val()
{
	std::cout << dp[a.size()][b.size()][c.size()];
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}

