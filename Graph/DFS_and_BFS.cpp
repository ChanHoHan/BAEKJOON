//1260
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

int N, M, V;
std::vector<int> graph[1001];
bool visited[1001];

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	int a, b;

	input_faster();
	std::cin >> N >> M >> V;
	for (int i = 0 ; i < M ; i++)
	{
		std::cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
}

void dfs(int index)
{
	std::cout << index << " ";
	std::sort(graph[index].begin(), graph[index].end());
	for (size_t i = 0 ; i < graph[index].size(); i++)
	{
		if (visited[graph[index][i]])
			continue;
		visited[graph[index][i]] = 1;
		dfs(graph[index][i]);
	}
}

void bfs()
{
	int x;

	std::queue<int> q;
	q.push(V);
	visited[V] = 1;
	while(!q.empty())
	{
		x = q.front();
		q.pop();
		std::cout << x << " ";
		for (size_t i = 0 ; i < graph[x].size() ; i++)
		{
			if (visited[graph[x][i]])
				continue;
			visited[graph[x][i]] = 1;
			q.push(graph[x][i]);
		}
	}
}

void solve()
{
	visited[V] = 1;
	dfs(V);
	std::cout << "\n";
	std::memset(visited, 0, sizeof(visited));
	bfs();
}

int main()
{
	input();
	solve();
	return (0);
}

