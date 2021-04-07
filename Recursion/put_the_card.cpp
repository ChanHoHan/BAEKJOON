//5568
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

int n, k, ans;
std::vector<int> cards;
bool table[100000003];

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> n >> k;
	cards.resize(n);
	for (int i = 0 ; i < n ; i++)
		std::cin >> cards[i];
}

void permutation(int index, int cnt, std::vector<std::string> save)
{
	if (index > n)
		return ;
	if (cnt == k)
	{
		std::sort(save.begin(), save.end());
		do
		{
			std::string a = "";
			for (auto &i : save)
				a += i;
			std::stringstream ss(a);
			int n;
			ss >> n;
			if (!table[n])
			{
				table[n] = 1;
				ans++;
			}
		} while(next_permutation(save.begin(), save.end()));
		return ;
	}
	for (int i = index; i < n; i++)
	{
		save.push_back(std::to_string(cards[i]));
		permutation(i + 1, cnt + 1, save);
		save.pop_back();
	}
}

void solve()
{
	permutation(0, 0, std::vector<std::string>());
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

