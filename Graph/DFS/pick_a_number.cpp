//2668
#include <iostream>
#include <vector>
#include <set>
#define endl "\n"

int N;
std::vector<int> graph;
std::set<int> ans;
bool visited[101];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> N;
	graph.resize(N + 1);
	for (int i = 1 ; i <= N ; i++)
		std::cin >> graph[i];
}

void dfs(int node, std::set<int> pre, std::set<int> will)
{
	if (visited[node])
		return ;
	pre.insert(node);
	will.insert(graph[node]);
	if (pre == will)
	{
		for(auto i = pre.begin() ; i != pre.end() ; i++)
		{
			visited[*i] = 1;
			ans.insert(*i);
		}
		return ;
	}
	if (pre.find(graph[node]) != pre.end())
		return ;
	dfs(graph[node], pre, will);
}

void solve()
{
	for (int i = 1 ; i <= N ; i++)
		dfs(i, std::set<int>(), std::set<int>());
}

void print_val()
{
	std::cout << ans.size() << endl;
	for (auto i = ans.begin() ; i != ans.end() ; i++)
		std::cout << *i << endl;
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}
