//1927
#include <iostream>
#include <vector>
#include <queue>

#define endl "\n"
int N;
std::priority_queue<int> pq;

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
	int op;

	while(N--)
	{
		std::cin >> op;
		if (!op)
		{
			if (pq.empty())
				std::cout << 0 << endl;
			else
			{
				std::cout << -pq.top() << endl;
				pq.pop();
			}
		}
		else
			pq.push(-op);
	}
}

int main()
{
	input();
	solve();
	return (0);
}
