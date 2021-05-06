//1107
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

int N, M, len, ans;
bool broken[11];

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
	std::cin >> N >> M;
	for (int i = 0 ; i < M ; i++)
	{
		std::cin >> tmp;
		broken[tmp] = 1;
	}
	len = std::to_string(N).size();
}

void brute(int channel, int depth)
{
	if (depth && std::abs(channel - N) + depth < ans)
		ans = std::abs(channel - N) + depth;
	if (depth == len + 1)
		return ;
	for (int i = 0 ; i < 10 ; i++)
		if (!broken[i])
			brute(channel * 10 + i, depth + 1);
}

void solve()
{
	ans = std::abs(100 - N);
	brute(0, 0);
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

