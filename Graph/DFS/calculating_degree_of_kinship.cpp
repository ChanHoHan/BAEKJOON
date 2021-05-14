//2644
#include <iostream>
#include <vector>
int n, m;
int start, end;
int ans = -1;
std::vector<std::vector<int> >relation;
bool visited[101];

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
	std::cin >> n >> start >> end >> m;
	relation.resize(101);
	for (int i = 0 ; i < m ; i++)
	{
		std::cin >> a >> b;
		relation[b].push_back(a);
		relation[a].push_back(b);
	}
}

bool dfs(int index, int cnt)
{
	int size_ = relation[index].size();

	if (index == end)
	{
		ans = cnt;
		return (1);
	}
	for (int i = 0 ; i < size_ ; i++)
	{
		if (visited[relation[index][i]])
			continue;
		visited[relation[index][i]] = 1;
		if (dfs(relation[index][i], cnt + 1))
			return (1);
	}
	return (0);
}

void solve()
{
	visited[start] = 1;
	dfs(start, 0);
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
