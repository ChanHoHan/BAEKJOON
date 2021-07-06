//1339
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

int N;
std::string words[11];
int words_num[11];
int max_len;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	std::string tmp;

	io_faster();
	std::cin >> N;
	for (int i = 0 ; i < N ; i++)
	{
		std::cin >> words[i];
		if (max_len < (int)words[i].size())
			max_len = words[i].size();
	}
	for (int i = 0 ; i < N ; i++)
	{
		tmp = "";
		for (int j = 0 ; j < max_len - (int)words[i].size() ; j++)
			tmp += " ";
		words[i] = tmp + words[i];
	}
}

void make_words_num(char *num_val)
{
	std::string tmp;

	for (int i = 0 ; i < N ; i++)
	{
		tmp = "";
		for (int j = 0 ; j < (int)words[i].size() ; j++)
		{
			if ('A' <= words[i][j] && words[i][j] <= 'Z')
				tmp += num_val[words[i][j] - 'A'];
		}
		words_num[i] = std::stoi(tmp);
	}
}

bool compare(std::pair<long long, int> a, std::pair<long long, int> b)
{
	return (a.first > b.first);
}

void solve()
{
	char num_val[26] = {0,};
	int ans = 0;
	std::pair<long long, int> numbers[26];

	for (int i = 0 ; i < 26 ; i++)
	{
		numbers[i].first = 0;
		numbers[i].second = i;
	}
	long long mul = std::pow(10, max_len);
	for(int i = 0 ; i < max_len ; i++)
	{
		for (int j = 0 ; j < N ; j++)
		{
			if ('A' <= words[j][i] && words[j][i] <= 'Z')
				numbers[words[j][i] - 'A'].first += mul;
		}
		mul /= 10;
	}
	std::sort(numbers, numbers + 26, compare);
	char val = '9';
	for (int i = 0 ; i < 26 ; i++)
	{
		if (!numbers[i].first)
			break;
		num_val[numbers[i].second] = val--;
	}

	make_words_num(num_val);
	for (int i = 0 ; i < N ; i++)
		ans+= words_num[i];
	std::cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}
