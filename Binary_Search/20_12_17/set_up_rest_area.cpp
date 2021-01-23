//1477
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int N,M,L;
std::vector <int> rest_area;
std::vector <int> section_dist;
std::vector <int> section_dist_num;
struct compare
{
	bool operator()(std::pair<int, int>a, std::pair<int, int>b)
	{
		return (a.first < b.first);
	}
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, compare > pq;
	int pq_top_val, pq_top_ind;
	int tmp;
	std::cin >> N >> M >> L;
	rest_area.resize(N + 2);

	rest_area[N+1] = L;
	section_dist.resize(N+2);
	section_dist_num.resize(N+2, 1); // 몇 번 나눴는지 체크
	for(size_t i = 0; i < static_cast<size_t>(N) ; i++)
	{
		std::cin >> tmp;
		if (tmp == 0)
			continue;
		rest_area[i] = tmp;
	}
	std::sort(rest_area.begin(), rest_area.end());
	for(size_t i = 1 ; i < static_cast<size_t>(N+2) ; i++)
	{
		pq.push({rest_area[i] - rest_area[i - 1], i - 1});
		section_dist[i - 1] = rest_area[i] - rest_area[i - 1];
	}
	while(M--)
	{
		pq_top_val = pq.top().first; // 나눈 값
		pq_top_ind = pq.top().second; // 차이의 index
		pq.pop();
		section_dist_num[pq_top_ind]++;
		if (section_dist[pq_top_ind] % section_dist_num[pq_top_ind])
			pq_top_val = (section_dist[pq_top_ind]) /
				section_dist_num[pq_top_ind] + 1;
		else
			pq_top_val = section_dist[pq_top_ind] /section_dist_num[pq_top_ind];
		pq.push({pq_top_val, pq_top_ind});
	}
	std::cout << pq.top().first;
	return (0);
}
