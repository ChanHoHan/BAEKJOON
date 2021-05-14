//18352
#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"
#define INF 3000000

int distance[300001];
std::vector<int> graph[300001];
std::priority_queue<std::pair<int, int> > pq;
int N, M, K, X;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	int node1, node2;

	io_faster();
	std::cin >> N >> M >> K >> X;
	for (int i = 0 ; i < M ; i++)
	{
		std::cin >> node1 >> node2;
		graph[node1].push_back(node2);
	}
	for (int i = 1 ; i <= N ; i++)
		distance[i] = INF;
}

void solve()
{
	int current, d, c_size, next, next_cost, fl = 0;

	distance[X] = 0;
	pq.push({0, X});
	while(!pq.empty())
	{
		d = -pq.top().first;
		current = pq.top().second;
		pq.pop();
		c_size = graph[current].size();
		for (int i = 0 ; i < c_size ; i++)
		{
			next = graph[current][i];
			next_cost = d + 1;
			if (next_cost > distance[next])
				continue;
			distance[next] = next_cost;
			pq.push({-next_cost, next});
		}
	}

	for (int i = 1 ; i <= N ; i++)
	{
		if (distance[i] == K)
		{
			std::cout << i << endl;
			fl = 1;
		}
	}
	if (!fl)
		std::cout << -1;
}

int main()
{
	input();
	solve();
	return (0);
}
