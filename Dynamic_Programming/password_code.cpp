//2011
#include <iostream>
#include <string>
std::string password;
int val[5001];
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
	std::cin >> password;
}

bool is_alpha(char ch)
{
	ch += 64;
	if ('A' <= ch && ch <= 'Z')
		return (1);
	return (0);
}

void solve()
{
	std::string a = "";

	if (password.size() >= 1)
	{
		if (password[0] == '0')
		{
			ans = 0;
			return ;
		}
		val[0] = 1;
	}
	if (password.size() >= 2)
	{
		a += password[0];
		a += password[1];
		
		if (password[1] == '0' && (password[0] >= '3'))
		{
			ans = 0;
			return ;
		}
		if (password[1] == '0' && is_alpha(std::stoi(a)))
			val[1] = 1;
		else if (is_alpha(std::stoi(a)))
			val[1] = 2;
		else
			val[1] = 1;
	}

	for (size_t i = 2 ; i < password.size() ; i++)
	{
		a = "";
		a += password[i - 1];
		a += password[i];
		if (password[i] == '0' && (password[i - 1] >= '3' || password[i - 1] == '0'))
		{
			ans = 0;
			return ;
		}
		if (password[i - 1] != '0' && is_alpha(std::stoi(a)))
			val[i] += val[i - 2];
		if ('1' <= password[i] && password[i] <= '9')
			val[i] += val[i - 1];
		val[i] %= 1000000;
	}
	ans = val[password.size() - 1];
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
