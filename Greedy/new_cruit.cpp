//1946
#include <iostream>
#include <algorithm>
#define endl "\n"
int T, N;
std::pair<int, int> cruit[100001];

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

void solve()
{
	int min_ = 100001, ans = 0;
	
	std::cin >> N;
	for (int i = 0 ; i < N ; i++)
		std::cin >> cruit[i].first >> cruit[i].second;
	std::sort(cruit, cruit + N);
	for (int i = 0 ; i < N ; i++)
	{
		if (cruit[i].second < min_)
		{
			min_ = cruit[i].second;
			ans++;
		}
	}
	std::cout << ans << endl;
}

int main()
{
	input();
	while (T--)
		solve();
	return (0);
}
