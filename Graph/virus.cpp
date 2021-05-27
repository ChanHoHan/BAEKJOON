//2606
#include <iostream>
#include <vector>

int N, M;
std::vector<int> computer[101];
bool visited[101];
int ans = 0;


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
	for (int i = 0 ; i < M ; i++)
	{
		std::cin >> a >> b;
		computer[a].push_back(b);
		computer[b].push_back(a);
	}
}

void dfs(int node)
{
	int size = computer[node].size();

	for (int i = 0 ; i < size ; i++)
	{
		if (visited[computer[node][i]])
			continue;
		visited[computer[node][i]] = 1;
		ans++;
		dfs(computer[node][i]);
	}
}

void solve()
{
	visited[1] = 1;
	dfs(1);
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
