//2252
#include <iostream>
#include <vector>
#include <queue>

int N, M;
std::queue<int> q;
int indegree[32001];
std::vector<std::vector<int> >graph;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	int a, b;

	io_faster();
	std::cin >> N >> M;
	graph.resize(N + 1);
	for (int i = 0 ; i < M ; i++)
	{
		std::cin >> a >> b;
		graph[a].push_back(b);
		indegree[b]++;
	}
}

void solve()
{
	for (int i = 1 ; i <= N ; i++)
	{
		if (indegree[i] == 0)
		{
			std::cout << i << " " ;
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		for (int node : graph[v])
		{
			if ((indegree[node] -= 1) == 0)
			{
				std::cout << node << " ";
				q.push(node);
			}
		}
	}

}

int main()
{
	input();
	solve();
	return (0);
}
