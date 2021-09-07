//1753
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define endl "\n"

int dist[20006], V, E, K;
std::vector<std::pair<int, int> > graph[20006];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	int a, b, c;

	std::cin >> V >> E;
	std::cin >> K;
	for (int i = 0 ; i < E ; i++) {
		std::cin >> a >> b >> c;
		graph[a].push_back({c, b});
	}
}

void solve()
{
	std::memset(dist, 0x3f, sizeof(dist)); // inf init
	std::priority_queue<std::pair<int, int> >q;
	dist[K] = 0;
	q.push({0, K});
	while(!q.empty()) {
		int cost = -q.top().first;
		int node = q.top().second;
		q.pop();
		if (dist[node] < cost) continue;
		for (size_t i = 0 ; i < graph[node].size() ; i++) {
			int next_node = graph[node][i].second;
			int next_cost = graph[node][i].first;
			if (next_cost + cost > dist[next_node]) continue;
			q.push({-(next_cost + cost), next_node});
			dist[next_node] = next_cost + cost;
		}
	}
	for (int i = 1 ; i <= V ; i++) {
		if (dist[i] == dist[20005]) std::cout << "INF" << endl;
		else std::cout << dist[i] << endl;
	}
}

int main()
{
	input();
	solve();
	return (0);
}
