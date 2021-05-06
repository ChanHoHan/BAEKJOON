//10597
#include <iostream>
#include <string>
#include <vector>

std::string s;
std::vector<int> ans;
int visited[51];
int N;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> s;
	if (s.size() <= 9)
		N = s.size();
	else
		N = (s.size() - 9) / 2 + 9;
}

bool dfs(int i)
{
	if ((int)ans.size() > N)
		return (0);
	if ((size_t)i >= s.size())
		return (1);
	if (s[i] - '0' > N || s[i] - '0' == 0)
		return 0;
	if (!visited[s[i] - '0'])
	{
		visited[s[i] -'0'] = 1;
		ans.push_back(s[i] - '0');
		if (dfs(i + 1))
			return 1;
		ans.pop_back();
		visited[s[i] - '0'] = 0;
	}
	if (i > (int)s.size() - 2)
		return 0;
	else
	{
		int val = (s[i] - '0')*10 + (s[i + 1] - '0');
		if (val > N || visited[val])
			return 0;
		visited[val] = 1;
		ans.push_back(val);
		if (dfs(i + 2))
			return 1;
		ans.pop_back();
		visited[val] = 0;
	}
	return 0;
}

void solve()
{
	dfs(0);
}

void print_val()
{
	for (size_t i = 0  ; i < ans.size(); i++)
		std::cout << ans[i] << " " ;
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}

