//2910
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define endl "\n"
int N, C;
std::map<int, int> um;
std::map<int, int>order;
std::vector<std::pair<int, int> >v;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

bool cmp(std::pair<int, int> a, std::pair<int, int> b)
{
	if (a.second ==  b.second)
		return (order[a.first] < order[b.first]);
	return (a.second > b.second);
}

void input()
{
	int tmp, o_index = 1;

	io_faster();
	std::cin >> N >> C;
	
	for (int i = 0 ; i < N ; i++)
	{
		std::cin >> tmp;
		if (um.find(tmp) != um.end())
			um[tmp] += 1;
		else
		{
			um[tmp] = 1;
			order[tmp] = o_index++;
		}
	}
	v = std::vector<std::pair<int, int> >(um.begin(), um.end());
	std::sort(v.begin(), v.end(), cmp);
}

void print_val()
{
	for (size_t i = 0 ; i < v.size() ; i++)
	{
		while (v[i].second--)
			std::cout << v[i].first << " ";
	}
}

int main()
{
	input();
	print_val();
	return (0);
}
