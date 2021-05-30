//18870
#include <iostream>
#include <algorithm>
#include <map>

int N;
int X[1000001];
int X_[1000001];

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
	{
		std::cin >> X[i];
		X_[i] = X[i];
	}
}

void solve()
{
	int val = 0, tmp;
	std::map<int, int> m;
	std::sort(X, X + N);
	tmp = X[0];
	m[tmp] = 0;
	for (int i = 0 ; i < N ; i++)
	{
		if (X[i] == tmp)
			continue;
		val++;
		m[X[i]] = val;
		tmp = X[i];
	}
	for (int i = 0 ; i < N ; i++)
		std::cout << m[X_[i]] << " ";
}

int main()
{
	input();
	solve();
	return (0);
}
