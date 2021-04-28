//2941
#include <iostream>
#include <string>
#include <unordered_set>

std::string word;
std::unordered_set<char> cs; //check set
std::unordered_set<std::string> ws; //word set
int ans;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> word;
	cs.insert('c');
	cs.insert('d');
	cs.insert('l');
	cs.insert('n');
	cs.insert('s');
	cs.insert('z');
	ws.insert("c=");
	ws.insert("c-");
	ws.insert("dz");
	ws.insert("dz=");
	ws.insert("d-");
	ws.insert("lj");
	ws.insert("nj");
	ws.insert("s=");
	ws.insert("z=");
}

bool is_possible(char ch)
{
	if (cs.find(ch) != cs.end())
		return (1);
	return (0);
}

bool word_check(std::string a)
{
	if (ws.find(a) != ws.end())
		return (1);
	return (0);
}


void solve()
{
	size_t i = -1;
	std::string tmp;

	while(++i < word.size())
	{
		if (is_possible(word[i]))
		{
			if (i < word.size() - 1 && word_check((tmp = word.substr(i, 2))))
			{
				if (tmp == "dz")
				{
					if (i < word.size() - 2 && word_check(word.substr(i, 3)))
						i += 2;
				}
				else
					i += 1;

			}
		}
		ans++;
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

