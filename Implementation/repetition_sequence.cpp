//2331
#include <iostream>
#include <unordered_set>
#include <cmath>
#include <vector>

int A, P;
std::unordered_set<int> s;
std::vector<int> v;
int ans = 0;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	int tmp;

	io_faster();
	std::cin >> A >> P;
	s.insert(A);
	v.push_back(A);
	while(true)
	{
		tmp = 0;
		while(A >= 10)
		{
			tmp += std::pow(A % 10, P);
			A /= 10;
		}
		tmp += std::pow(A, P);
		if (s.find(tmp) != s.end())
		{
			for (size_t i = 0 ; i < v.size() ; i++)
			{
				if (v[i] == tmp)
					return ;
				ans++;
			}
			return ;
		}
		else
		{
			s.insert(tmp);
			v.push_back(tmp);
		}
		A = tmp;
	}
}

void print_val()
{
	std::cout << ans;
}

int main()
{
	input();
	print_val();
	return (0);
}
