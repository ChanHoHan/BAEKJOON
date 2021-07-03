//5904
#include <iostream>
int N;
long long arr[33];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> N;
	arr[0] = 3;
	for (int i = 1; i < 33; i++)
		arr[i] = 2 * arr[i - 1] + (i + 3);
}

void solve()
{
	int ind;

	for (int i = 2 ; i < 33 ; i++)
		if (arr[i] > N)
		{
			ind = i - 1;
			break;
		}
	
	while (ind > 2)
	{
		
		ind--;
	}
}

int main()
{
	input();
	solve();
	return (0);
}
