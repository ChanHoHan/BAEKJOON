//1202
#include <iostream>
#include <algorithm>
#include <queue>

int N, K;
long long ans;
std::pair<int, int> jewelry[300001];
int bag_weight[300001];

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
	for (int i = 0 ; i < N ; i++)
		std::cin >>jewelry[i].first >> jewelry[i].second;
	for (int i = 0 ; i < K ; i++)
		std::cin >> bag_weight[i];
	std::sort(jewelry, jewelry + N);
	std::sort(bag_weight, bag_weight + K);
}

void solve()
{
	std::priority_queue<int> pq;
	int posjewelry = 0;

	for (int i = 0 ; i < K ; i++)
	{
		int curbag = bag_weight[i];

		while (posjewelry < N && jewelry[posjewelry].first <= curbag)
		{
			pq.push(jewelry[posjewelry].second);
			posjewelry++;
		}
		if (!pq.empty())
		{
			ans += pq.top();
			pq.pop();
		}
	}
	std::cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}
