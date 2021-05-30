//1764
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define endl "\n"
int N, M;

std::set<std::string> a;
std::vector<std::string> ans;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void solve()
{
	std::string tmp;

	io_faster();
	std::cin >> N >> M;
	for (int i = 0 ; i < N ; i++)
	{
		std::cin >> tmp;
		a.insert(tmp);
	}
	for (int i = 0 ; i < M ; i++)
	{
		std::cin >> tmp;
		if (a.find(tmp) != a.end())
			ans.push_back(tmp);
	}
	std::sort(ans.begin(), ans.end());
	std::cout << ans.size() << endl;
	for (size_t i = 0 ; i < ans.size() ; i++)
		std::cout << ans[i] << endl;
}

int main()
{
	solve();
	return (0);
}

