#include <cstdio>
#define MAX 1000000000
typedef long long ll;

ll ans, odds;
int X, Y;

void binary_search(int min, int max)
{
	if (min > max)
		return ;
	ll mid = (((ll)min + (ll)max) / 2);
	ll cal_odds = static_cast<ll>((((double)mid + (double)Y) /
				((double)X + (double)mid))* 100);
	
	if (odds < cal_odds)
	{
		ans = mid;
		binary_search(min, mid - 1);
	}
	else
		binary_search(mid + 1, max);
}

int main()
{
	scanf("%d %d", &X, &Y);
	odds = static_cast<ll>(((double)Y) * 100) / (double)X;
	ans = -1;
	if (odds != 100)
		binary_search(1, MAX);

	printf("%lld", ans);

	return (0);
}
