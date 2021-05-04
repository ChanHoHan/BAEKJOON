//16987
#include <iostream>
#include <algorithm>

int N, ans = 0;
std::pair<int, int> eggs[9];

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
		std::cin >> eggs[i].first >> eggs[i].second;
}

void brute(int ind, std::pair<int, int> eggs_parameter[])
{
	int fl = 0, cnt = 0;

	if (ind == N)
	{
		for (int i = 0 ; i < N ; i++)
			if (eggs_parameter[i].first <= 0)
				cnt++;
		ans = std::max(ans, cnt);
		return ;
	}
	if (eggs_parameter[ind].first <= 0)
	{
		brute(ind + 1, eggs_parameter);
		return ;
	}
	for (int i = 0; i < N ; i++)
	{
		if (i == ind || eggs_parameter[i].first <= 0)
			continue;
		fl = 1;
		eggs_parameter[ind].first -= eggs_parameter[i].second;
		eggs_parameter[i].first -= eggs_parameter[ind].second;
		brute(ind + 1, eggs_parameter);
		eggs_parameter[ind].first += eggs_parameter[i].second;
		eggs_parameter[i].first += eggs_parameter[ind].second;
	}
	if (!fl)
		brute(ind + 1, eggs_parameter);
}

void solve()
{
	brute(0, eggs);
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
