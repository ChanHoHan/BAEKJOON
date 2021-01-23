#include <cstdio>
#include <algorithm>
typedef long long ll;

int A[4001];
int B[4001];
int C[4001];
int D[4001];
int answer[16000001];

int main()
{
	int N, tmp;
	int lower, upper;
	ll ans;

	scanf("%d", &N);
	for (int i = 0 ; i < N ; i++)
		scanf("%d %d %d %d", &A[i],&B[i],&C[i],&D[i]);
	
	int index = 0;
	for (int i = 0 ; i < N ; i++)
		for (int j = 0 ; j < N ; j++)
			answer[index++] = C[i] + D[j];
	std::sort(answer, answer + index);
	ans = 0;
	for (int i = 0 ; i < N ; i++)
	{
		for (int j = 0 ; j < N; j++)
		{
			tmp = A[i] + B[j];
			tmp = -tmp;
			lower = std::lower_bound(answer, answer + index, tmp) - answer + 1;
			upper = std::upper_bound(answer, answer + index, tmp) - answer + 1;
			ans += (upper - lower);
		}
	}
			

	printf("%lld", ans);
	return (0);
}
