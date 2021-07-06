//1759
#include <iostream>
#include <algorithm>
#include <string>
#define endl "\n"
int L, C;
char password[16];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> L >> C;
	for (int i = 0 ; i < C ; i++)
		std::cin >> password[i];
	std::sort(password, password + C);
}

void comb(int depth, std::string word, int index)
{
	if (depth == L)
	{
		int word_size = word.size();
		int con = 0;
		int vow = 0;
		for (int i = 0 ; i < word_size ; i++)
			if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
				vow++;
		con = word_size - vow;
		if (con < 2 || vow < 1)
			return ;
		std::cout << word << endl;
		return;
	}
	for (int i = index ; i < C ; i++)
		comb(depth + 1, word + password[i], i + 1);
}

void solve()
{
	comb(0, "", 0);
}

int main()
{
	input();
	solve();
	return (0);
}
