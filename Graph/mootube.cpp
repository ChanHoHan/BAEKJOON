//15591
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define endl "\n"

int N, Q;
std::vector<std::pair<int, int> > usa[5001];
std::vector<std::pair<int, int> >question;
int min_val;
bool visited[5001];
int dist[5001];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	int p, q, r, k, v;

	io_faster();
	std::cin >> N >> Q;
	question.resize(Q);
	for (int i = 0 ; i < N - 1; i++)
	{
		std::cin >> p >> q >> r;
		usa[p].push_back({q, r});
		usa[q].push_back({p, r});
	}
	for (int i = 0 ; i < Q ; i++)
	{
		std::cin >> k >> v;
		question[i] = {k, v};
	}
}

void dfs(int node, int min_val)
{
	int next_node, val;

	for (size_t i = 0 ; i < usa[node].size(); i++)
	{
		next_node = usa[node][i].first;
		val = std::min(usa[node][i].second, min_val);
		if (visited[next_node])
			continue;
		if (dist[next_node] > val)
			dist[next_node] = val;
		visited[next_node] = 1;
		dfs(next_node, val);
		visited[next_node] = 0;
	}
}

void solve()
{
	int start, K, cnt;

	for (int i = 0 ; i < Q ; i++)
	{
		K = question[i].first;
		start = question[i].second;
		std::memset(visited, 0, sizeof(visited));
		std::fill(dist, dist + 5001, 1000000001);
		visited[start] = 1;
		dfs(start, 1000000001);
		cnt = 0;
		for (int i = 1 ; i <= N ; i++)
		{
			if (i == start)
				continue;
			if (dist[i] >= K)
				cnt++;
		}
		std::cout << cnt << endl;
	}
}

int main()
{
	input();
	solve();
	return (0);
}

