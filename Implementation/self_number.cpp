//4673
#include <iostream>
#define endl "\n"
int val[10001];

void solve()
{
	int x, y;

	for (int i = 1 ; i <= 10000; i++)
	{
		x = i;
		y = i;
		while (x >= 10)
		{
			y += x % 10;
			x /= 10;
		}
		y += x;
		val[y] = 1;
	}
	for (int i = 1 ; i <= 10000 ; i++)
		if (!val[i])
			std::cout << i << endl;
}

int main()
{
	solve();
	return (0);
}
