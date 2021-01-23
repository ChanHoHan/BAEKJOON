//2872
#include <iostream>

int N, cnt;
void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}
void input()
{
	input_faster();
	std::cin >> N;
	cnt = 0;
	int i_max = 0;
	int tmp;
	std::cin >> tmp;
	i_max = tmp;
	for(int i = 1 ; i < N; i++)
	{
		std::cin >> tmp;
		if (tmp > i_max)
		{
			if (tmp - i_max > 1)
				cnt++;
			i_max = tmp;
		}
		else
			cnt++;
	}
}

int main()
{
	input();
	std::cout << cnt;
	return (0);
}

