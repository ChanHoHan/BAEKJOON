#include <iostream>
#include <vector>

std::vector<std::vector<std::pair<int, int> > >bridge_and_weight;
int N, M;
int mid, ans, is_reached, start, end;
std::vector<bool> visited;

void dfs(int st)
{
	if (visited.at(st) || is_reached)
		return ;
	if (st == end)
	{
		is_reached = 1;
		return ;
	}
	visited.at(st) = 1;
	for(size_t i = 0 ; i < bridge_and_weight[st].size() ; i++)
	{
		if (bridge_and_weight[st][i].second < mid || is_reached)
			continue;
		else
			dfs(bridge_and_weight[st][i].first);
	}
}

void binary_search(int min, int max)
{
	if (min > max)
		return ;
	mid = (min + max) /2;
	is_reached = 0;
	visited = std::vector<bool>(N + 1 , false);
	dfs(start);
	if(!is_reached)
		binary_search(min, mid-1);
	else
	{
		ans = mid;
		binary_search(mid+1, max);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);


	int MAX_WEIGHT = 0;
	std::cin >> N >> M;
	bridge_and_weight.resize(N + 1);
	int a, b, c;
	for(int i = 0 ; i < M ; i++)
	{
		std::cin >> a >> b >> c;
		if (MAX_WEIGHT < c)
			MAX_WEIGHT = c;
		bridge_and_weight[a].push_back(std::make_pair(b, c));
		bridge_and_weight[b].push_back(std::make_pair(a, c));
	}
	std::cin >> start >> end;
	binary_search(0, MAX_WEIGHT);

	std::cout << ans;
	return (0);
}
