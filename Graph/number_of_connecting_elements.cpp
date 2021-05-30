//11724
#include <iostream>
#include <vector>

std::vector<int> v[1001];
bool visited[1001];
int N, M, ans;

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
	for(int i = 0 ; i < M ; i++)
	{
		std::cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
}

void dfs(int index)
{
	int size = v[index].size();

	for (int i = 0 ; i < size ; i++)
	{
		if (visited[v[index][i]])
			continue;
		visited[v[index][i]] = 1;
		dfs(v[index][i]);
	}
}

void solve()
{
	for (int i = 1 ; i <= N ; i++)
	{
		if (visited[i])
			continue;
		visited[i] = 1;
		dfs(i);
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
