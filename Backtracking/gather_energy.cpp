//16198
#include <iostream>

int N, ans;
int energy[11];
bool visited[11];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> N;
	for (int i = 0 ; i < N ; i++)
		std::cin >> energy[i];
}

void brute_force(int size, int val)
{
	int left, right;

	if (size == 3)
	{
		val += (energy[0] * energy[N-1]);
		if (ans < val)
			ans = val;
	}
	for (int i = 1 ; i < N - 1 ; i++)
	{
		if (visited[i])
			continue;
		visited[i] = 1;
		left = i;
		right = i;
		while (visited[--left])
			;
		while (visited[++right])
			;
		brute_force(size - 1, val + (energy[left] * energy[right]));
		visited[i] = 0;
	}
}

void solve()
{
	brute_force(N, 0);
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
