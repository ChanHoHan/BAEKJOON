//14890
#include <iostream>
#include <cmath>

int N, L;
int g_map[101][101];
int ans, cnt;

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> N >> L;
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < N ; j++)
			std::cin >> g_map[i][j];
	ans = 0;
}

bool investigate_col(int x)
{
	int before;
	int now;
	int runway = 0;
	int bigger = 0;

	before = g_map[0][x];
	for (int i = 0 ; i < N ; i++)
	{
		now = g_map[i][x];
		if (std::abs(before - now) >= 2)
			return (0);
		if (bigger && before - now < 0 && runway)
			return (0);
		else if (!bigger && before - now > 0 && runway)
			return (0);
		if (std::abs(before - now) <= 1 && runway)
		{
			runway--;
			if (!runway)
				before = now;
		}
		if (std::abs(before - now) == 1 && !runway)
		{
			runway = L - 1;
			if (before > now)
				bigger = 1;
			if (!runway)
				before = now;
		}
	}
	if (runway)
		return (0);
	return (1);
}

bool investigate_row(int y)
{
	int before;
	int now;
	int runway = 0;
	int bigger = 0;
	before = g_map[y][0];
	for (int i = 0 ; i < N ; i++)
	{
		now = g_map[y][i];
		if (std::abs(before - now) >= 2)
			return (0);
		if (bigger && before - now < 0 && runway)
			return (0);
		else if (!bigger && before - now > 0 && runway)
			return (0);

		if (std::abs(before - now) <= 1 && runway)
		{
			runway--;
			if (!runway)
				before = now;
		}
		if (std::abs(before - now) == 1 && !runway)
		{
			runway = L - 1;
			if (!runway)
				before = now;
		}
	}
	if (runway)
		return (0);
	return (1);
}

void solve()
{

	for (int i = 0 ; i < N ; i++) // loop row
		if(investigate_row(i))
			ans++;
	for (int j = 0 ; j < N ; j++) // loop col
		if(investigate_col(j))
			ans++;
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

