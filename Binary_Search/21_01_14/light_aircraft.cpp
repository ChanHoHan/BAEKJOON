#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

int n, k;
std::vector<std::pair<int, int> >oil_supply;
std::vector<bool> visited;
int oil_min, oil_max;
int b_mid, ans;

double cal_distance(int x1, int y1, int x2, int y2) // 거리 계산
{
	return(std::sqrt(std::pow((x2 - x1), 2) + std::pow((y2 - y1), 2)));
}

int cal_need_oil(size_t a, size_t b)
{
	int x1 = oil_supply[a].first;
	int y1 = oil_supply[a].second;
	int x2 = oil_supply[b].first;
	int y2 = oil_supply[b].second;
	int dis = static_cast<int>(std::ceil(cal_distance(x1, y1, x2, y2)));
	if (dis%10)
		return (dis/10 + 1);
	else
		return (dis/10);
}

bool bfs()
{
	std::queue<std::pair<int, int> >q; // cnt, now
	q.push(std::make_pair(0, 0));
	std::pair<int, int> a;
	while (!q.empty())
	{
		a = q.front();
		q.pop();
		if (cal_need_oil(a.second, n+1) <= b_mid)
			return (true);
		if (a.first > k)
			continue;
		for(size_t i = 1; i < static_cast<size_t>(n + 1); i++)
		{
			if (!visited[i] && cal_need_oil(a.second, i) <= b_mid)
			{
				visited[i] = true;
				q.push(std::make_pair(a.first + 1, i));
			}
		}
	}
	return (false);
}

void binary_search(int b_min, int b_max)
{
	if (b_min > b_max)
		return ;
	b_mid = (b_min + b_max) / 2;
	visited = std::vector<bool>(n, false);
	if(bfs())
	{
		ans = b_mid;
		binary_search(b_min, b_mid - 1);
	}
	else
	{
		binary_search(b_mid + 1, b_max);
	}
}

void solve(void)
{
	binary_search(oil_min, oil_max);
}

void input_faster(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input(void)
{
	input_faster();
	std::cin >> n >> k;
	oil_supply.resize(n+2);
	oil_supply[0].first = 0;
	oil_supply[0].second = 0;
	oil_supply[n+1].first = 10000;
	oil_supply[n+1].second = 10000;
	oil_max = 1415;
	oil_min = 0;
	for(size_t i = 1 ; i < static_cast<size_t>(n + 1) ; i++)
		std::cin >> oil_supply[i].first >> oil_supply[i].second;
}

int main(void)
{
	input();
	solve();
	std::cout << ans;
	return (0);
}
