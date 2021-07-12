//2458
#include <iostream>
#include <vector>
#include <cstring>

int N, M;
std::pair<int, int> in_out[501];
std::vector<std::vector<int> >graph;
bool visited[501];

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
	}
}

int record_indegree(int node)
{
	int size = graph[node].size();
	int cnt = 0;
	in_out[node].first++;
	for (int i = 0 ; i < size ; i++)
	{
		if (visited[graph[node][i]])
			continue;
		visited[graph[node][i]] = 1;
		cnt += (1 + record_indegree(graph[node][i]));
	}
	return (cnt);
}

void solve()
{
	int ans = 0;

	for (int i = 1 ; i <= N ; i++)
	{
		std::memset(visited, 0, sizeof(visited));
		int size = graph[i].size();
		for (int j = 0 ; j < size ; j++)
		{
			if (!visited[graph[i][j]])
			{
				visited[graph[i][j]] = 1;
				in_out[i].second += (1 + record_indegree(graph[i][j]));
			}
		}
	}
	for (int i = 1 ; i <= N ; i++)
	{
		if (in_out[i].first + in_out[i].second == N - 1)
			ans++;
	}
	std::cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}

