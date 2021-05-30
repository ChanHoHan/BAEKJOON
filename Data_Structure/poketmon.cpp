//1620
#include <iostream>
#include <map>
#include <string>
#include <vector>
#define endl "\n"

int N, M;
std::map<std::string, int> m;
std::vector<std::string> v;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	std::string tmp;

	io_faster();
	std::cin >> N >> M;
	v.resize(N + 1);
	for (int i = 1 ; i <= N ; i++)
	{
		std::cin >> tmp;
		v[i] = tmp;
		m[tmp] = i;
	}
}

void solve()
{
	std::string tmp;

	for (int i = 0 ; i < M ; i++)
	{
		std::cin >> tmp;
		if ('0' <= tmp[0] && tmp[0] <= '9')
			std::cout << v[stoi(tmp)] << endl;
		else
			std::cout << m[tmp] << endl;
	}
}

int main()
{
	input();
	solve();
	return (0);
}
