#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"

int w, b;
int cnt, score;
std::string longest_word;

std::vector<std::string> dice;
std::vector<bool> visited;
std::vector<std::pair<int, int> >dir;
struct trie;
trie *p;
bool not_count;

int to_number(char ch)
{
	return (ch - 'A');
}

void score_board(std::string &word)
{
	if (word.size() == 3 || word.size() == 4)
		score += 1;
	else if (word.size() == 5)
		score += 2;
	else if (word.size() == 6)
		score += 3;
	else if (word.size() == 7)
		score += 5;
	else if (word.size() == 8)
		score += 11;
}
struct trie
{
	std::vector<trie *>children;
	std::vector<bool> t_visited;
	bool terminal;
	trie(): terminal(false)
	{
		children.resize(26, nullptr);
		t_visited.resize(30, 0);
	}
	~trie()
	{
		for(size_t i = 0 ; i < 26; i++)
			if(children[i])
				delete children[i];
	}

	void insert(std::string &key, int i)
	{
		if (key[i] == '\0')
			terminal = true;
		else
		{
			int next = to_number(key[i]);
			if (children[next] == nullptr)
				children[next] = new trie();
			children[next]->insert(key, i + 1);
		}
	}

	trie* find(std::string &key, int i, int &boggle)
	{
		if (key[i] == '\0')
		{
			if ((t_visited[boggle] && terminal) || !terminal)
				not_count = 1;
			else if (terminal)
				t_visited[boggle] = true;
			return (this);
		}
		int next = to_number(key[i]);
		if (children[next] == nullptr)
			return (nullptr);
		return (children[next]->find(key, i+1, boggle));
	}
};

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	int i = -1;

	input_faster();
	std::cin >> w;
	p = new trie();
	while(++i < w)
	{
		std::string tmp;
		std::cin >> tmp;
		p->insert(tmp, 0);
	}
	std::cin >> b;
	dir = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
}

void dfs(int i, int j, std::string word, int &boggle)
{
	if (i < 0 || j < 0 || i >= 4 || j >= 4 || visited[i*4 + j] || word.size() > 8)
		return ;
	word.push_back(dice[i][j]);
	not_count = 0;
	if (p->find(word, 0, boggle) == nullptr)
		return;
	visited[i*4 + j] = 1;
	if (!not_count)
	{
		if(word.size() > longest_word.size())
		{
			longest_word = "";
			longest_word = word;
		}
		else if (word.size() == longest_word.size())
		{

			if(word.compare(longest_word) < 0)
			{
				longest_word = "";
				longest_word = word;

			}
		}
		cnt++;
		score_board(word);
	}
	for (size_t x = 0 ; x < 8 ; x++)
		dfs (i + dir[x].first, j + dir[x].second, word, boggle);
	visited[i*4 + j] = 0;
}

void solve()
{
	int i;
	std::string word;

	score = 0;
	cnt = 0;
	i = -1;
	dice = std::vector<std::string>(4);
	while (++i < 4)
	{
		dice[i].resize(4);
		std::cin >> dice[i];
	}
	word = "";
	longest_word = "";
	for(int i = 0 ; i < 4 ; i++)
		for(int j = 0 ; j < 4 ; j++)
		{
			visited = std::vector<bool> (16,0);
			dfs(i, j , word, b);
		}
	std::cout << score << " " << longest_word << " " << cnt << endl;
}

int main()
{
	input();
	while(b--)
		solve();
	delete (p);
	return (0);
}
