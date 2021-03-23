//10773
#include <cstdio>
#include <stack>
int main()
{
	int K, tmp, ans;
	std::stack <int> s;

	scanf("%d", &K);
	ans = 0;
	for (int i = 0 ; i < K; i++)
	{
		scanf("%d", &tmp);
		if (tmp != 0)
		{
			ans += tmp;
			s.push(tmp);
		}
		else
		{
			tmp = s.top();
			ans -= tmp;
			s.pop();
		}
	}
	printf("%d", ans);

	return (0);
}
