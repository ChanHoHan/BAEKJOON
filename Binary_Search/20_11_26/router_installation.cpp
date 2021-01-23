#include <cstdio>
#include <algorithm>

int house[200001];
int N, C;
int ans;

int router_cal(int val_mid)
{
	int start = house[0];
	int the_number_of_routers = 1;

	for(int i = 1 ; i < N; i++)
	{
		if (house[i] - start >= val_mid)
		{
			the_number_of_routers += 1;
			start = house[i];
		}
	}
	return (the_number_of_routers);
}


void binary_search_index(int val_start, int val_end)
{
	if (val_start > val_end)
		return ;
	int val_mid = (val_start + val_end) / 2;
	int the_number_of_routers = router_cal(val_mid);
	if (the_number_of_routers >= C)
	{
		ans = val_mid;
		binary_search_index(val_mid + 1, val_end);
	}
	else
		binary_search_index(val_start, val_mid - 1);
}


void solve()
{
	int val_start, val_end;

	val_start = 1;
	val_end = house[N - 1] - house[0];
	binary_search_index(val_start, val_end);
}

int main()
{
	int tmp;
	
	scanf("%d %d", &N, &C);
	for(int i = 0 ; i < N ; i++)
	{
		scanf("%d", &tmp);
		house[i] = tmp;
	}
	std::sort(house, house + N);
	ans = 1;

	solve();
	printf("%d", ans);
	return (0);
}
