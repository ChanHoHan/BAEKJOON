//1922
#include <iostream>
#include <vector>
#include <algorithm>

int N, M;
std::vector<std::pair<int, std::pair<int, int> > >graph;
int root[1001];

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
		graph.push_back({cost, {a, b}});
	}
	std::sort(graph.begin(), graph.end());
}

int u_find(int x)
{
	if (x == root[x])
		return (x);
	return (root[x] = u_find(root[x]));
}

int u_union(int a, int b)
{
	a = u_find(a);
	b = u_find(b);
	if (a == b)
		return (0);
	root[a] = b;
	return (1);
}


void solve()
{
	int a, b, cost, ans = 0;

	for (int i = 1 ; i <= N ; i++)
		root[i] = i;
	for (int i = 0 ; i < M ; i++)
	{
		cost = graph[i].first;
		a = graph[i].second.first;
		b = graph[i].second.second;
		if (u_union(a, b))
			ans += cost;
	}
	std::cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}
