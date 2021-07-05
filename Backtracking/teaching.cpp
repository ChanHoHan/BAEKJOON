//1062
#include <iostream>
#include <vector>
#include <string>
#define endl "\n"
int N, K;

std::vector<std::string> lang;
int g_max = 0;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	std::string a;

	io_faster();
	std::cin >> N >> K;
	for (int i = 0 ; i < N ; i++)
	{
		std::cin >> a;
		lang.push_back(a);
	}
}

void check(int visited)
{
	int lang_size = lang.size(), word_size, cnt = 0, fl;

	std::string word;

	for (int i = 0 ; i < lang_size ; i++)
	{
		word = lang[i];
		word_size = word.size();
		fl = 0;
		for (int j = 0 ; j < word_size ; j++)
		{
			if (!((1 << (word[j] - 'a')) & visited))
			{
				fl = 1;
				break;
			}
		}
		if (fl)
			continue;
		cnt++;
	}
	g_max = g_max > cnt ? g_max : cnt;
}

void backtracking(int index, int visited, int visited_size)
{
	if (visited_size == K)
	{
		check(visited);
		return ;
	}
	for (int i = index ; i < 26 ; i++)
	{
		if (visited != ((1 << i) | visited))
			backtracking(i + 1, (1 << i) | visited, visited_size + 1);
	}
}


void solve()
{
	int visited = 0;
	visited = (1 << ('a' - 'a')) | (1 << ('c' - 'a')) | (1 << ('i' - 'a')) | (1 << ('n' - 'a')) | (1 << ('t' - 'a'));
	backtracking(1, visited, 5);
	std::cout << g_max;
}

int main()
{
	input();
	solve();
	return (0);
}
