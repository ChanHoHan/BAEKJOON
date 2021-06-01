//7490
#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"

int T;
std::vector<std::vector<char> > ans;
std::string op = "+- ";

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> T;
}

bool is_op(char ch)
{
	for (int i = 0 ; i < 2 ; i++)
		if (ch == op[i])
			return (1);
	return (0);
}

void operation(int save, int &tmp, char save_op)
{
	if (save_op == '+')
		tmp = tmp + save;
	else if (save_op == '-')
		tmp = tmp - save;
}

int cal(std::vector<char> v)
{
	int tmp = 0;
	int save = 0;
	size_t ind = -1;
	char save_op = 'x';


	std::string a = " ";
	for (size_t i = 0 ; i < v.size(); i++)
	{
		if (v[i] == ' ')
			continue;
		a+=v[i];
	}
	while (++ind <= a.size())
	{
		if (ind == a.size())
		{
			if (is_op(save_op))
				operation(save, tmp, save_op);
			else
				tmp = save;
			break;
		}
		if (isdigit(a[ind]))
			save = save * 10 + a[ind] - '0';
		else
		{
			if (!is_op(save_op))
				tmp = save;
			else if (is_op(a[ind]))
				operation(save, tmp, save_op); 
			save_op = a[ind];
			save = 0;
		}
	}
	return (tmp);
}

void recursion(std::vector<char> v, int ind)
{
	if (v.size() <= (size_t)ind)
	{
		if (!cal(v))
			ans.push_back(v);
		return ;
	}
	for (int i = 0 ; i < 3 ; i++)
	{
		v[ind] = op[i];
		recursion(v, ind + 2);
	}
}

void solve()
{
	int N;

	std::cin >> N;
	std::vector<char> v;
	ans = std::vector<std::vector<char> >();
	for (int i = 1 ; i <= N ; i++)
	{
		v.push_back(i + '0');
		if (i == N)
			break;
		v.push_back(' ');
	}
	recursion(v, 1);
	std::sort(ans.begin(), ans.end());
	for(size_t i = 0 ; i < ans.size() ; i++)
	{
		for (size_t j = 0 ; j < ans[i].size() ; j++)
			std::cout << ans[i][j];
		std::cout << endl;
	}
	std::cout << endl;
}

int main()
{
	input();
	while(T--)
		solve();
	return (0);
}
