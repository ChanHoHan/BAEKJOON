#include <cstdio>
#include <cstring>

bool card[20000001];
int main()
{
	int N, M;
	int tmp;

	scanf("%d", &N);
	memset(card, 0, sizeof(card));
	for(int i = 0 ; i < N ;i++)
	{
		scanf("%d", &tmp);
		if (tmp >= 0)
			card[tmp] = 1;
		else
		{
			tmp = 10000000 + (-tmp);
			card[tmp] = 1;
		}
	}
	scanf("%d", &M);
	for(int i = 0 ; i < M ; i++)
	{
		scanf("%d", &tmp);
		if (tmp >= 0)
			printf("%d ", card[tmp]);
		else
			printf("%d ", card[-tmp + 10000000]);
	}

	return 0;
}
