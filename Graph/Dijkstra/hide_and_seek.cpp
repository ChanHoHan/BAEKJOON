//13549
#include <iostream>
#include <algorithm>
#include <queue>

std::priority_queue<std::pair<int, int> > pq;
int N, K, ans;
int distance[100001];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> N >> K;
	std::fill(distance, distance + 100001, 100000000);
}

void dijkstra()
{
	int node, dist, i;

	pq.push({0, N});
	distance[N] = 0;
	if (N == K)
		return ;
	while(!pq.empty())
	{
		dist = -pq.top().first;
		node = pq.top().second;
		pq.pop();

		i = 2 * node;
		if (node != 0)
		{
			while (i <= 100000)
			{
				if (distance[i] < dist)
				{
					i *= 2;
					continue;
				}
				pq.push({-dist, i});
				distance[i] = dist;
				i *= 2;
			}
		}
		if (node - 1 >= 0 && distance[node - 1] > dist + 1)
		{		
			distance[node - 1] = dist + 1;
			pq.push({-(dist + 1), node - 1});
		}
		if (node + 1 <= 100000 && distance[node + 1] > dist + 1)
		{
			distance[node + 1] = dist + 1;
			pq.push({-(dist + 1), node + 1});
		}
	}
}

void solve()
{
	dijkstra();
}

void print_val()
{
	std::cout << distance[K];
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}
