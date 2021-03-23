// 2935
#include <iostream>
#include <string>

int main()
{
	std::string a,op, b;
	std::cin >> a >> op >> b;
	int a_len, b_len;
	a_len = a.size();
	b_len = b.size();
	if (op[0] == '+')
	{
		if (a_len == b_len)
		{
			std::cout << '2';
			for(int i = 0 ; i < a_len - 1 ; i++)
				std::cout << '0';
		}
		else if (a_len > b_len)
		{
			std::cout << '1';
			a_len -= b_len;
			a_len -= 1;
			for(int i = 0 ; i < a_len ; i++)
				std::cout << '0';
			std::cout << '1';
			for(int i = 0 ; i < b_len - 1 ; i++)
				std::cout << '0';
		}
		else
		{
			std::cout << '1';
			b_len -= a_len;
			b_len -= 1;
			for(int i = 0 ; i < b_len ; i++)
				std::cout << '0';
			std::cout << '1';
			for(int i = 0 ; i < a_len - 1 ; i++)
				std::cout << '0';
		}

	}
	else if (op[0] == '*')
	{
		a_len += b_len;
		a_len -= 2;
		std::cout << '1';
		for(int i = 0 ; i < a_len; i++)
			std::cout << '0';
	}
	return (0);
}
