//14496
#include <iostream>
#include <vector>
#include <queue>

std::queue<std::pair<int, int> >q;
std::vector<std::vector<int> >graph;
bool visited[1001];
int a,b,N,M, ans = -1;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	int x, y;

	io_faster();
	std::cin >> a >> b >> N >> M;
	graph.resize(N + 1);
	for (int i = 0 ; i < M ; i++)
	{
		std::cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
}

void bfs()
{
	int node, d;

	if (a == b)
	{
		ans = 0;
		return;
	}
	q.push({a, 0});
	visited[a] = 1;
	while (!q.empty())
	{
		node = q.front().first;
		d = q.front().second;
		q.pop();
		for (size_t i = 0 ; i < graph[node].size() ;i++)
		{
			if (visited[graph[node][i]])
				continue;
			if (graph[node][i] == b)
			{
				ans = d + 1;
				return ;
			}
			visited[graph[node][i]] = 1;
			q.push({graph[node][i], d + 1});
		}
	}
}

void solve()
{
	bfs();
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
