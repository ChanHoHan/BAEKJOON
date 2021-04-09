//1302
#include <iostream>
#include <unordered_map>

int N;
std::string ans;
std::unordered_map<std::string, int> mp;

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	std::string tmp;

	input_faster();
	std::cin >> N;
	for (int i = 0 ; i < N ; i++)
	{
		std::cin >> tmp;
		if (mp.find(tmp) != mp.end())
			mp[tmp] += 1;
		else
			mp[tmp] = 1;
	}
}

void solve()
{
	int _min = 0;

	for (const auto& i : mp)
	{
		if (i.second > _min)
		{
			ans = i.first;
			_min = i.second;
		}
		else if (i.second == _min)
			ans = i.first < ans ? i.first : ans;
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

