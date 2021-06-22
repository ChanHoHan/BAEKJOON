//3273
#include <iostream>
#include <algorithm>
int n, table[100001], x;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> n;
	for (int i = 0 ; i < n ; i++)
		std::cin >> table[i];
	std::sort(table, table + n);
	std::cin >> x;
}

void solve()
{
	int left = 0, right = n - 1, val, ans = 0;;

	while (left < right)
	{
		val = table[left] + table[right];
		if (val == x)
			ans++;
		if (val >= x)
			right--;
		else
			left++;
	}
	std::cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}
