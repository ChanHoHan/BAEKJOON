//11724
#include <iostream>
#include <vector>

size_t N, M;
std::vector<std::vector<int> >graph;
bool visited[1001];
int ans;

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
	std::cin >> N >> M;
	graph.resize(N + 1);
	for (size_t i = 0 ; i < M ; i++)
	{
		std::cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
}

void dfs(int i)
{
	for (size_t j = 0 ; j < graph[i].size(); j++)
	{
		if (visited[graph[i][j]])
			continue;
		visited[graph[i][j]] = 1;
		dfs(graph[i][j]);
	}
}

void solve()
{
	for (size_t i = 1 ; i <= N ; i++)
	{
		if (visited[i])
			continue;
		ans++;
		visited[i] = 1;
		dfs(i);
	}
}

void print_val()
{
	std::cout << ans;
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}

