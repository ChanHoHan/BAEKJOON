//2164
#include <iostream>
#include <deque>

int N;
std::deque<int> q;

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
	for (int i = N ; i >= 1 ; i--)
		q.push_back(i);
}

void solve()
{
	while (q.size() != 1)
	{
		q.pop_back();
		q.push_front(q.back());
		q.pop_back();
	}
	std::cout << q.back();
}

int main()
{
	input();
	solve();
	return (0);
}
