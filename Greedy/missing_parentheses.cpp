//1541
#include <iostream>
#include <vector>

std::string inp;
std::vector<int> v;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> inp;
}

void solve()
{
	int i = -1, tmp = 0, v_size = 0, fl = 1, ans, size = inp.size();

	while(++i <= size)
	{
		if (i == size)
		{
			if (fl)
			{
				v.push_back(tmp);
				v_size++;
			}
			else
				v[v_size - 1] += tmp;
			break;
		}
		if (isdigit(inp[i]))
		{
			tmp*=10;
			tmp += (inp[i] - '0');
		}
		else if (inp[i] == '+' || inp[i] == '-')
		{
			if (fl) // '-'
			{
				v.push_back(tmp);
				v_size++;
			}
			else
				v[v_size - 1] += tmp;
			tmp = 0;
			if (inp[i] == '+')
				fl = 0;
			else
				fl = 1;
		}
	}
	ans = v[0];
	for (int i = 1 ; i < v_size ; i++)
		ans -= v[i];
	std::cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}
