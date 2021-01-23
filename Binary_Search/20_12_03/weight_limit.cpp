//1939
#include <cstdio>
#include <cstring>
#include <vector>
#define MAX 1000000000

std::vector <int> bridge[10001];
std::vector <int> weight[10001];
int N, M;
int start, end;
int mid, ans, val;
bool visited[100001];

void dfs(int st)
{
	if (visited[st] || val)
		return ;
	if (st  == end)
	{
		val = 1;
		return;
	}
	visited[st] = 1;
	for(size_t i = 0; i < bridge[st].size() ; i++)
	{
		if (weight[st][i] < mid)
			continue;
		else
			dfs(bridge[st][i]);
	}		
}

void binary_search(int min, int max)
{
	if (min > max)
		return;
	mid = (min + max) / 2;
	val = 0;
	memset(visited, 0, sizeof(visited));
	dfs(start);
	if (!val)
		binary_search(min, mid-1);
	else
	{
		ans = mid;
		binary_search(mid+1, max);
	}
}

int main()
{
	int a,b,c;

		scanf("%d %d", &N, &M);
	
	for(int i = 0 ; i < M ; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		bridge[a].push_back(b);
		bridge[b].push_back(a);
		weight[a].push_back(c);
		weight[b].push_back(c);
	}
	scanf("%d %d", &start, &end);
	binary_search(0, MAX);

	printf("%d", ans);
	return (0);
}

