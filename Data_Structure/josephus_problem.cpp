//1158
#include <iostream>
#include <queue>

std::queue<int> q;
int N, K;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> N >> K;
	for(int i = 1 ; i <= N ; i++)
		q.push(i);
}

void solve()
{
	std::cout << "<";
	while(!q.empty())
	{
		for (int i = 0 ; i < K - 1 ; i++)
		{
			q.push(q.front());
			q.pop();
		}
		std::cout << q.front();
		q.pop();
		if (!q.empty())
			std::cout << ", ";
	}
	std::cout << ">";
}

int main()
{
	input();
	solve();
	return (0);
}

