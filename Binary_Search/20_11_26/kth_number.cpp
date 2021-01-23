#include <cstdio>
typedef long long ll;

ll N;
ll K;
ll ans;

ll calcul(ll mid)
{
	ll rtn_val = 0;
	for(int i = 1 ; i <= N; i++)
	{
		if (i * N <= mid)
			rtn_val += N;
		else
			rtn_val += (mid / i);
	}
	return (rtn_val);
}

void binary_search(ll start, ll end)
{
	if (start > end)
		return;
	ll mid = (start + end) / 2;
	ll cal_val = calcul(mid);
	
	if (cal_val >= K)
	{
		ans = mid;
		binary_search(start, mid - 1);
	}
	else
		binary_search(mid + 1, end);
}

int main()
{

	scanf("%lld %lld", &N, &K);
	binary_search(1, N*N);

	printf("%lld", ans);
	
	return (0);
}
