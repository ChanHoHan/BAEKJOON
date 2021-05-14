//17413
#include <iostream>
#include <cstring>

char word[100001];
std::string ans;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin.getline(word, 100001);
}

void solve()
{
	int i = -1;
	while (word[++i])
		;
	int w_size = i;

	i = -1;
	ans = "";
	std::string save = "";

	while (++i <= w_size)
	{
		if (save.size() > 0 && (i == w_size || word[i] == ' ' || word[i] == '<'))
		{
			for (int j = save.size() - 1 ; j >= 0 ; j--)
				ans+=save[j];
			save = "";
			if (word[i] == ' ')
			{
				ans += word[i];
				continue;
			}
			if (i == w_size)
				break;
		}

		if (word[i] == '<')
		{
			ans+=word[i];
			while(word[++i] != '>')
				ans+=word[i];
			ans+=word[i];
		}
		else
			save+=word[i];
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
