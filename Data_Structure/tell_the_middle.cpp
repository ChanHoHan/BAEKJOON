//1655
#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"

int N;
std::priority_queue<int> max_pq;
std::priority_queue<int, std::vector<int>, std::greater<int> >min_pq;

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
}

void solve()
{
	int a;

	for (int i = 0 ; i < N ; i++)
	{
		std::cin >> a;

		if (min_pq.size() == max_pq.size())
			max_pq.push(a);
		else
			min_pq.push(a);
		if (!min_pq.empty() && !max_pq.empty() && min_pq.top() < max_pq.top())
		{
			int min_v = min_pq.top();
			min_pq.pop();
			int max_v = max_pq.top();
			max_pq.pop();
			max_pq.push(min_v);
			min_pq.push(max_v);
		}
		std::cout << max_pq.top() << endl;
	}
}

int main()
{
	input();
	solve();
	return (0);
}
