//2941
#include <iostream>
#include <string>

std::string word;
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
}

void solve()
{
	size_t i = -1;

	while(++i < word.size())
	{
		if (i < word.size() - 1)
		{
			if ((word[i] == 'c' && (word[i+1] == '=' || word[i+1] == '-')))
				i+=1;
			else if ((word[i] == 'd' && (word[i+1] == '-')))
				i+=1;
			else if ((word[i+1] == 'j') && (word[i] == 'l' || word[i] == 'n'))
				i+=1;
			else if (i < word.size() - 2 && word[i] == 'd' && word[i+1] == 'z' && word[i+2] == '=')
				i+=2;
			else if ((word[i+1] == '=') && (word[i] == 's' || word[i] == 'z'))
				i+=1;
		}
		ans++;
	}
}

void print_val()
{
	std::cout << ans << "\n";
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}
