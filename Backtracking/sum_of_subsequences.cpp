//1182
#include <iostream>

int N, S;
int sq[21];
int ans, max_depth;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> N >> S;
	for (int i = 0 ; i < N ; i++)
		std::cin >> sq[i];
}

void brute_force(int index, int val, int depth)
{
	if (depth == max_depth)
	{
		if (val == S)
			ans++;
		return;
	}
	for (int i = index; i < N ; i++)
		brute_force(i + 1, val + sq[i], depth + 1);
}

void solve()
{
	for (int i = 1 ; i <= N ; i++)
	{
		max_depth = i;
		brute_force(0, 0, 0);
	}
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

