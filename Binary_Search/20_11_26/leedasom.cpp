#include <iostream>
#include <string>
#include <map>
#include <ctype.h>
#define endl "\n"
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int N,M;
	std::string k;
	std::cin >> N >> M;
	std::map <std::string, int> pokemon_name;
	std::map <int, std::string> pokemon_number;

	for (int i = 0 ; i < N; i++)
	{
		std::cin >> k;
		pokemon_name.insert(make_pair(k, i+1));
		pokemon_number.insert(make_pair(i+1, k));
	}

	int x;

	for (int i = 0 ; i < M ; i++)
	{
		std::cin >> k;
		if (isdigit(k[0]))
		{
			x = std::stoi(k);
			std::cout << pokemon_number.find(x)->second << endl;
		}
		else
			std::cout << pokemon_name.find(k)->second << endl;
	}

	return 0;
}
