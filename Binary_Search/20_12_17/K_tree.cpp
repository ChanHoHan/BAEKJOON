//11812
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
typedef long long ll;

std::vector<ll> height_val;
std::vector<std::pair<ll, ll> >section_range;
int ans;

void find_parent(ll& node, int height, std::vector <ll> &parents, int &K)
{
	if(height == 0)
	{
		parents.push_back(1);
		return ;
	}
	ll parent_index;
	while(node != 1)
	{
		parent_index = (node - section_range[height--].first)/ K;
		/* 예를 들면, K = 3 이라고 하고 section_range[height].first가 5라 하자.
	 그리고 node 10 의 부모를 알고싶으면, 5 + K*parent_index = 10 이다.*/

		node = section_range[height].first + parent_index;
		parents.push_back(node);
	}
}

void cal(ll &x, ll &y, int &K)
{
	int x_height = 0;
	int y_height = 0;
	std::vector <ll>x_parents;
	std::vector <ll>y_parents;
	for(size_t i = 0; i < section_range.size() ; i++)
	{
		if (x >= section_range[i].first && x <= section_range[i].second)
			x_height = i;
		if (y >= section_range[i].first && y <= section_range[i].second)
			y_height = i;
	}
	//부모 겹치는거 구하기
	find_parent(x, x_height, x_parents, K);
	find_parent(y, y_height, y_parents, K);
	std::sort(x_parents.begin(), x_parents.end());
	std::sort(y_parents.begin(), y_parents.end());
	size_t index = 0;
	int cnt = 0;
	while(index < x_parents.size() && index < y_parents.size())
	{
		if (x_parents[index] != y_parents[index])
			break;
		index++;
		cnt++;
	}
	ans = x_height + y_height - 2 * (cnt - 1);
}


void make_val(ll &N, int &K)
{
	ll tmp = 1;

	while(tmp <= N*K)
	{
		height_val.push_back(tmp);
		tmp *= K;
	}
	size_t index = 1;
	section_range.resize(height_val.size());
	section_range[0].first = 1;
	section_range[0].second = 1;
	while(index < height_val.size())
	{
		section_range[index].first = section_range[index - 1].second + 1;
		section_range[index].second = height_val[index] +
			section_range[index - 1].second;
		index++;
	}
}


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	ll N;
	int K, Q;
	std::cin >> N >> K >> Q;
	if (K != 1)
		make_val(N,K);	
	ll x, y;
	for(int i = 0 ; i < Q ; i++)
	{
		std::cin >> x >> y;
		if (K == 1)
			std::cout << std::abs(y - x) << "\n";
		else
		{
			cal(x, y, K);
			std::cout << ans << "\n";
		}
	}
	return (0);
}
