//1039
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>

int n, k;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> n >> k;
}

int swap_val(int x, int y, int num)
{
	char tmp;

	std::string s_num = std::to_string(num);
	tmp = s_num[x];
	s_num[x] = s_num[y];
	s_num[y] = tmp;
	if (s_num[0] == '0')
		return (-1);
	return (std::stoi(s_num));
}

void solve()
{
	if ((1 <= n && n <= 9) || ((10 <= n && n <= 90 && !(n % 10))))
	{
		std::cout << -1;
		return;
	}
	int num, num_size = std::to_string(n).size(), tmp;
	std::queue<int> q;
	q.push(n);

	for (int i = 0 ; i < k ; i++)
	{
		int size = q.size();
		std::set<int> visited;
		std::queue<int> new_q;
		for (int j = 0 ; j < size ; j++)
		{
			num = q.front();
			q.pop();
			for (int x = 0 ; x < num_size - 1; x++)
			{
				for (int y = x + 1 ; y < num_size ; y++)
				{
					tmp = swap_val(x, y, num);
					if (visited.find(tmp) != visited.end() || tmp == -1)
						continue;
					visited.insert(tmp);
					new_q.push(tmp);
				}
			}
		}
		q = new_q;
	}
	int max_ = 0;
	while (!q.empty())
	{
		if (max_ < q.front())
			max_ = q.front();
		q.pop();
	}	
	std::cout << max_;
}

int main()
{
	input();
	solve();
	return (0);
}
