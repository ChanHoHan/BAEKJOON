#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define endl "\n"
std::vector<std::pair<int, int> > graph[1002];
std::priority_queue<std::pair<int, int> > pq;
int bus_cost[1002];

int N, M, start, end;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	int a, b, cost;

	io_faster();
	std::cin >> N >> M;
	for (int i = 0 ; i < M ; i++)
	{
		std::cin >> a >> b >> cost;
		graph[a].push_back({cost, b});
	}
	std::cin >> start >> end;
}

void solve()
{
	pq.push({0, start});
	std::memset(bus_cost, 0x3f, sizeof(bus_cost));
	bus_cost[start] = 0;
	while(!pq.empty())
	{
		int cost = -pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (bus_cost[node] < cost) continue;
		int size = graph[node].size();
		for (int i = 0 ; i < size ; i++) 
		{
			int next_cost = graph[node][i].first + cost;
			int next_node = graph[node][i].second;
			if (next_cost < bus_cost[next_node])
			{
				bus_cost[next_node] = next_cost;
				pq.push({-next_cost, next_node});
			}
		}
	}
	std::cout << bus_cost[end];
}

int main()
{
	input();
	solve();
	return (0);
}
