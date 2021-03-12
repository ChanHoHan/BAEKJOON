//9252
#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"

std::string a;
std::string b;
std::vector<std::vector<int> >LCS;

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> a;
	std::cin >> b;
	LCS.resize(b.size() + 1, std::vector<int>(a.size() + 1));
}

void solve()
{
	for (size_t i = 1 ; i <= b.size() ; i++)
		for (size_t j = 1 ; j <= a.size() ; j++)
		{
			if (a[j - 1] == b[i - 1])
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			else
				LCS[i][j] = std::max(LCS[i][j - 1] , LCS[i - 1][j]);
		}
}

void dfs(int b_i, int a_i, int val)
{
	if (b_i <= 0 || a_i <= 0 || val == 0)
		return ;
	// up
	int up = LCS[b_i - 1][a_i];
	int left = LCS[b_i][a_i - 1];
	if (up == val)
		dfs(b_i - 1, a_i, up);
	else if (left == val)
		dfs(b_i, a_i - 1, left);
	else if (left != val)
	{
		dfs(b_i, a_i - 1, left);
		std::cout << b[b_i - 1];
	}
}

void print_val()
{
	int cnt = 0;
	
	std::cout << LCS[b.size()][a.size()] << endl;
	dfs(b.size(), a.size(), LCS[b.size()][a.size()]);
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}
