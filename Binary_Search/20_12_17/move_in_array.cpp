//1981
#include <iostream>
#include <algorithm>
#include <vector>

int n;
std::vector<std::vector <int> >arr;
std::vector<int> value;
std::vector<bool> visited;
int ans;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

bool dfs(int i, int j, int min, int max)
{
	if (i <= 0 || i > n || j <= 0 || j > n)
		return (0);
	if (visited[(i - 1)*n + (j - 1)] || arr[i][j] > value[max] || arr[i][j] < value[min])
		return (0);
	if (i == n && j == n)
		return (1);
	visited[(i - 1) * n + (j - 1)] = true;
	for(int k = 0 ; k < 4; k++)
	{
		if (dfs(i + dx[k] , j + dy[k], min, max))
			return (1);
	}
	return (0);
}

void solve()
{
	int min = 0;
	int max = 0;
	ans = 202;
	while(max < value.size())
	{
		visited = std::vector<bool>(n * n, false);
		if (dfs(1, 1, min, max))
		{
			if (value[max] - value[min] < ans)
				ans = value[max] - value[min];
			min++;
			continue;
		}
		max++;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	std::cin >> n;
	value.resize(n*n);
	arr.resize(n+1);
	for(int i = 1 ; i < n + 1 ; i++)
	{
		arr[i].resize(n+1);
		for(int j = 1 ; j < n + 1 ; j++)
		{
			std::cin >> arr[i][j];
			value[(i - 1) * n + j - 1] = arr[i][j];
		}
	}
	std::sort(value.begin(), value.end());
	value.erase(std::unique(value.begin(), value.end()), value.end());
	solve();
	std::cout << ans;
	return(0);
}
