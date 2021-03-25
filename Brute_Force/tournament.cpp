//1057
#include <iostream>
#include <algorithm>

int N, ans;
int kim, lim;
int num[100001];
int num_tmp[100001];

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> N >> kim >> lim;
	for (int i = 1 ; i <= N ; i++)
		num[i] = 1;
	ans = 1;
}

bool battle(int left_person)
{
	int i = 1;
	int a, b;

	while (i + 1 <= left_person)
	{
		a = i;
		b = i + 1;
		if ((a == kim && b == lim) || (a == lim && b == kim))
			return (1);
		if (a == kim || a == lim)
			num[b] = 0;
		else if (b == kim || b == lim)
			num[a] = 0;
		else // random
			num[a] = 0;
		i += 2;
	}
	return (0);
}

void update(int left_person, int& ind)
{
	for (int i = 1 ; i <= left_person ; i++)
	{
		if (num[i])
		{
			num_tmp[ind] = 1;
			if (i == kim)
				kim = ind;
			else if (i == lim)
				lim = ind;
			ind++;
		}
	}
}

void solve()
{
	int round, left_person, ind;

	round = 1;
	left_person = N;
	while (left_person != 1)
	{
		ind = 1;
		if (battle(left_person))
		{
			ans = round;
			return ;
		}
		update(left_person, ind);
		std::copy(num_tmp, num_tmp + ind, num);
		left_person = ind;
		round++;
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

