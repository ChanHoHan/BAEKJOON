//4256
#include <iostream>
#include <cstring>

#define endl "\n"
int T, n;
int pre[1001];
int in[1001];
int pre_ind;

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

int find_in_index()
{
	if (pre_ind > n)
		return (-1);
	int pre_val = pre[pre_ind];
	for (int i = 1 ; i <= n ; i++)
		if (pre_val == in[i])
			return (i);
	return (-1);
}

void post_order(int start, int end)
{
	if (start > end)
		return ;
	pre_ind++;
	int in_ind = find_in_index();
	if (in_ind == -1)
		return ;
	post_order(start, in_ind - 1);
	post_order(in_ind + 1, end);
	std::cout << in[in_ind] << " ";
}

void solve()
{
	std::cin >> n;
	for (int i = 1 ; i <= n ; i++)
		std::cin >> pre[i];
	for (int i = 1 ; i <= n ; i++)
		std::cin >> in[i];
	post_order(1, n);
}

int main()
{
	input();
	while (T--)
	{
		std::memset(pre, 0, sizeof(pre));
		std::memset(in, 0, sizeof(in));
		pre_ind = 0;
		solve();
		std::cout << endl;
	}
	return (0);
}

