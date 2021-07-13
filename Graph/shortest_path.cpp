//1753
#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"
#define INF 99999999

int V, E, K;
std::vector<std::vector<std::pair<int, int> > >graph;
std::priority_queue<std::pair<int, int> >pq;

int dist[20001];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	int u,v,w;

	io_faster();
	std::cin >> V >> E >> K;
	graph.resize(V + 1);
	for (int i = 1 ; i <= V ; i++)
		dist[i] = INF;
	for (int i = 0 ; i < E ; i++)
	{
		std::cin >> u >> v >> w;
		graph[u].push_back({w, v});
	}
}

void solve()
{
	int node, value, next_node, next_value;

	dist[K] = 0;
	for (auto i : graph[K])
		pq.push({-i.first, i.second});
	while (!pq.empty())
	{
		value = -pq.top().first;
		node = pq.top().second;
		pq.pop();
		if (dist[node] <= value)
			continue;
		dist[node] = value;
		for (auto i : graph[node])
		{
			next_node = i.second;
			next_value = i.first + value;
			if (dist[next_node] < next_value)
				continue;
			pq.push({-next_value, next_node});
		}
	}
	for (int i = 1 ; i <= V ; i++)
	{
		if (dist[i] == INF)
			std::cout << "INF";
		else
			std::cout << dist[i];
		std::cout << endl;
	}
}


int main()
{
	input();
	solve();
	return (0);
}
