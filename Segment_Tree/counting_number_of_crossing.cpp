//1615
#include <iostream>
#include <algorithm>
int N, M;
typedef std::pair<int, int> pii;
pii graph[1999999];
int seg[8000];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

bool compare(pii a, pii b)
{
	if (a.first == b.first)
		return (a.second < b.second);
	return (a.first < b.first);
}

int seg_sum(int node, int s, int e, int l, int r)
{
	if (e < l || r < s)
		return (0);
	if (l <= s && e <= r)
		return (seg[node]);
	return (seg_sum(2 * node, s , (s + e) / 2, l, r) + seg_sum(2 * node + 1, (s + e) / 2 + 1, e, l, r));
}

void update(int node, int s, int e, int idx, int val)
{
	if (idx < s || e < idx)
		return ;
	if (s == e)
		seg[node] += val;
	else
	{
		update(node * 2, s, (s + e) / 2, idx, val);
		update(node * 2 + 1, (s + e) / 2 + 1, e, idx, val);
		seg[node] = seg[node * 2] + seg[node * 2 + 1];
	}
}

void input()
{
	int a, b;

	io_faster();
	std::cin >> N >> M;
	for (int i = 0 ; i < M ; i++)
	{
		std::cin >> a >> b;
		graph[i].first = a;
		graph[i].second = b;
	}
	std::sort(graph, graph + M, compare);
}

void solve()
{
	int a, b, ans = 0;

	for (int i = 0 ; i < M ; i++)
	{
		a = graph[i].first;
		b = graph[i].second;
		ans += seg_sum(1, 1, N, b + 1, N);
		update(1, 1, N, b, 1);
	}
	std::cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}

