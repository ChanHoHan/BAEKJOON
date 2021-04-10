//11725
#include <iostream>
#include <vector>

#define endl "\n"
int N;
std::vector<int> tree[100001];
std::vector<int> ans;
std::vector<int> visited;

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
	std::cin >> N;
	ans.resize(N + 1);
	visited.resize(N + 1);
	for (int i = 0 ; i < N - 1 ; i++)
	{
		std::cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
}

void dfs(int index, int before_index)
{
	ans[index] = before_index;
	visited[index] = 1;
	for (int i = 0 ; i < tree[index].size(); i++)
		if (!visited[tree[index][i]])
			dfs(tree[index][i], index);
}

void solve()
{
	dfs(1, 0);
}

void print_val()
{
	for (int i = 2 ; i <= N ; i++)
		std::cout << ans[i] << endl;
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}

