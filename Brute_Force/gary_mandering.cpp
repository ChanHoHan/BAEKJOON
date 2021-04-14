//17471
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

int N, dfs_depth;
std::vector<int> g_map[11];
std::vector<int> population;
std::vector<int> a;
std::vector<int> b;
bool visited[11];
bool check[11];
int ans = 9999;
std::vector<std::vector<int>::iterator> address;
std::vector<std::vector<int>::iterator> vec_end;
int a_population, b_population;

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	int tmp, num;

	io_faster();
	std::cin >> N;
	population.resize(N + 1);
		
	for (int i = 1 ; i <= N ; i++)
		std::cin >> population[i];
	for (int i = 1 ; i <= N ; i++)
	{
		std::cin >> num;
		for (int j = 0 ; j < num ; j++)
		{
			std::cin >> tmp;
			g_map[i].push_back(tmp);
		}
	}
	vec_end.resize(2);
	address.resize(2);
}

void is_linked(int index)
{
	for (int i = 0 ; i < g_map[index].size(); i++)
	{
		if (visited[g_map[index][i]])
			continue;
		visited[g_map[index][i]] = 1;
		is_linked(g_map[index][i]);
	}
}

bool link_check(int ind)
{
	int cnt = 0;

	std::memset(visited, 0, sizeof(visited));
	for (auto i = address[ind] ; i != vec_end[ind] ; i++)
		visited[*i] = 1;
	visited[*address[!ind]] = 1;
	is_linked(*address[!ind]);
	for (int i = 1 ; i <= N ; i++)
		cnt += visited[i];
	if (cnt != N)
		return (0);
	return (1);
}

void combination(int index, int depth)
{
	if (depth == dfs_depth)
	{
		int fl;

		b.clear();
		std::memset(check, 0, sizeof(check));
		for (int i = 0 ; i < a.size() ; i++)
			check[a[i]] = 1;
		for (int i = 1 ; i <= N ; i++)
			if (!check[i])
				b.push_back(i);
		if (!a.size() || !b.size())
			return;
		address[0] = a.begin();
		address[1] = b.begin();
		vec_end[0] = a.end();
		vec_end[1] = b.end();
		if(!link_check(0) || !link_check(1))
			return;
		a_population = 0;
		b_population = 0;
		for (int i = 0 ; i < a.size(); i++)
			a_population += population[a[i]];
		for (int i = 0 ; i < b.size(); i++)
			b_population += population[b[i]];
		if (std::abs(a_population - b_population) < ans)
			ans = std::abs(a_population - b_population);
		return;
	}
	for (int i = index + 1 ; i <= N; i++)
	{
		a.push_back(i);
		combination(i, depth + 1);
		a.pop_back();
	}
}

void solve()
{
	for (int i = 1 ; i <= N / 2 ; i++)
	{
		dfs_depth = i;
		combination(0, 0);
	}
}

void print_val()
{
	if (ans == 9999)
	{
		std::cout << -1;
		return ;
	}
	std::cout << ans;
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}

