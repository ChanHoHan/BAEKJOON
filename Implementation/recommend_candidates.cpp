//1713
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> photos;
std::vector<int> ans;
int N, S;

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> N >> S;
	photos.resize(101);
}

void solve()
{
	int tmp;

	while (S--)
	{
		int _min = 999999, _min_index;
		std::cin >> tmp;
		if (std::find(ans.begin(), ans.end(), tmp) != ans.end())
			photos[tmp]+=1;
		else if (ans.size() < N)
		{
			ans.push_back(tmp);
			photos[tmp] = 1;
		}
		else
		{
			for (int i = 0 ; i < ans.size() ; i++)
			{
				if (photos[ans[i]] < _min)
				{
					_min = photos[ans[i]];
					_min_index = i;
				}
			}
			photos[ans[_min_index]] = 0;
			ans.erase(ans.begin() + _min_index);
			ans.push_back(tmp);
			photos[tmp] = 1;
		}	
	}
}

void print_val()
{
	std::sort(ans.begin(), ans.end());
	for (auto & i : ans)
		std::cout << i << " ";
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}
