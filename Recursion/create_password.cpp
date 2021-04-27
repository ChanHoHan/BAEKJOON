//1759
#include <iostream>
#include <algorithm>
#include <unordered_set>

#define endl "\n"

int L, C;
char password[16];
std::unordered_set<char> vo;//모음
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
	vo.insert('a');
	vo.insert('e');
	vo.insert('i');
	vo.insert('o');
	vo.insert('u');
}



bool is_possible(std::string& ans)
{
	int v = 0, c = 0;

	for (size_t i = 0 ; i < ans.size() ; i++)
	{
		if (vo.find(ans[i]) != vo.end())
			v++;
		else
			c++;
	}
	if (v < 1 || c < 2)
		return (0);
	return (1);
}

void combination(int index, int depth, std::string ans)
{
	if (depth == L)
	{
		if (is_possible(ans))
			std::cout << ans << endl;
		return ;
	}
	if (index >= C)
		return ;
	for (int i = index ; i < C ; i++)
		combination(i + 1, depth + 1, ans + password[i]);
}

void solve()
{
	combination(0, 0, "");
}

int main()
{
	input();
	solve();
	return (0);
}

