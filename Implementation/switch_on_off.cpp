//1244
#include <iostream>
#define endl "\n"

int N, Students_N;
bool state[101];
std::pair<int, int>students[101];

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
	for (int i = 1 ; i <= N ; i++)
		std::cin >> state[i];
	std::cin >> Students_N;
	for (int i = 0 ; i < Students_N ; i++)
		std::cin >> students[i].first >> students[i].second;
}

void girl(int num)
{
	int left = num;
	int right = num;
	
	while (true)
	{
		if (state[left] != state[right] || left <= 0 || right > N)
		{
			left += 1;
			right -= 1;
			break;
		}
		left -= 1;
		right += 1;
	}
	for (int i = left ; i <= right ; i++)
	{
		if (state[i])
			state[i] = 0;
		else
			state[i] = 1;
	}
}

void boy(int num)
{
	for (int i = 1 ; i <= N ; i++)
	{
		if (!(i % num))
		{
			if (state[i])
				state[i] = 0;
			else
				state[i] = 1;
		}
	}
}

void solve()
{
	int sex, num;

	for (int i = 0 ; i < Students_N ; i++)
	{
		sex = students[i].first;
		num = students[i].second;
		if (sex == 1)
			boy(num);
		else
			girl(num);
		
	}

}

void print_val()
{
	for (int i = 1 ; i <= N ; i++)
	{
		if (!(i % 20))
			std::cout << state[i];
		else
			std::cout << state[i] << " ";
		if (!(i % 20))
			std::cout << endl;

	}
}

int main()
{
	input();
	solve();
	print_val();
	return (0);
}
