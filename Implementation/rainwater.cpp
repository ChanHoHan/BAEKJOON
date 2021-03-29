//14719
#include <iostream>

int blocks[502];
int H, W;
int ans;

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	input_faster();
	std::cin >> H >> W;
	for (int i = 0 ; i < W ; i++)
		std::cin >> blocks[i];
}

void solve()
{
	int l_block;

	for (int i = 1 ; i <= H ; i++)
	{
		l_block = -1;
		for (int j = 0 ; j < W ; j++)
		{
			if (blocks[j] >= i)
			{
				if (l_block == -1)
				{
					l_block = j;
					continue;
				}
				ans += (j - l_block - 1);
				l_block = j;
			}
		}
	}
}

void print_val()
{
	std::cout << ans;
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}

