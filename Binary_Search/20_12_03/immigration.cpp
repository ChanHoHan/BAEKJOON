#include <cstdio>
typedef long long ll;

int N,M;
ll N_t[100001];
ll ans;

int cal_val(ll mid)
{
	ll quo = 0;

	for(int i = 0 ; i < N ; i++)
		quo += mid / N_t[i];
	if (quo >= M)
		return (1);
	else
		return (0);
}

void binary_search(ll min, ll max)
{
	if (min > max)
		return ;
	ll mid = (min + max) / 2;
	int val = cal_val(mid);
	if (val)
	{
		if (ans > mid)
			ans = mid;
		binary_search(min, mid - 1);
	}
	else
		binary_search(mid + 1, max);
}

int main()
{
	ll MAX = 0;
	scanf("%d %d", &N, &M);
	for(int i = 0 ; i < N; i++)
	{
		scanf("%lld", &N_t[i]);
		if (MAX < N_t[i])
			MAX = N_t[i];
	}
	MAX *= M;

	ans = MAX;
	binary_search(1, MAX);

	printf("%lld", ans);
	return (0);
}
