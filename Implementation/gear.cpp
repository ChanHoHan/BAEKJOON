#include <iostream>
#include <string>

int A[9];
int B[9];
int C[9];
int D[9];
int state[3];
std::string a, b, c, d;
void make_gear()
{
	int *x;
	std::string y;
	int val, index;
	for(int i = 0 ; i < 4 ; i++)
	{
		if (i == 0)
		{
			x = A;
			y = a;
		}
		else if (i == 1)
		{
			x = B;
			y = b;
		}
		else if (i == 2)
		{
			x = C;
			y = c;
		}
		else
		{
			x = D;
			y = d;
		}
		for(int j = 0 ; j < 8 ; j++)
			x[j] = static_cast<int>(y[j]) - 48;
	}
}
	

void spin_gear_clock_or_counter(int *x, int dir)
{
	int tmp;
	int tmp2;

	if (dir == -1)
	{
		tmp = x[7];
		for(int i = 1 ; i < 8 ; i++)
			x[(6 + i) % 8] = x[i - 1];
		x[6] = tmp;
	}
	else
	{
		tmp = x[0];
		for(int i = 0 ; i < 8 ; i ++)
		{
			tmp2 = x[(i + 1) % 8];
			x[(i + 1) % 8] = tmp;
			tmp = tmp2;
		}
	}
}

int *switch_val(int x)
{
	if (x == 1)
		return A;
	else if (x == 2)
		return B;
	else if (x == 3)
		return C;
	else
		return D;
}

void spin_gear(int num, int dir)
{
	
	spin_gear_clock_or_counter(switch_val(num), dir);
	if (num == 1)
	{
		for (int i = 0 ; i < 3 ; i++)
		{
			if (state[i] == 0)
				break;
			dir *= -1;
			num += 1;
			spin_gear_clock_or_counter(switch_val(num), dir);
		}
	}
	else if (num == 2)
	{
		if (state[0] == 1)
			spin_gear_clock_or_counter(switch_val(num - 1), -dir);
		if (state[1] == 1)
		{
			dir *= -1;
			spin_gear_clock_or_counter(switch_val(num + 1), dir);
			if (state[2] == 1)
				spin_gear_clock_or_counter(switch_val(num + 2), -dir);
		}
	}
	else if (num == 3)
	{
		if (state[2] == 1)
			spin_gear_clock_or_counter(switch_val(num + 1), -dir);
		if (state[1] == 1)
		{
			dir *= -1;
			spin_gear_clock_or_counter(switch_val(num - 1), dir);
			if (state[0] == 1)
				spin_gear_clock_or_counter(switch_val(num - 2), -dir);
		}
	}
	else
	{
		for (int i = 2 ; i >= 0 ; i--)
		{
			if (state[i] == 0)
				break;
			dir *= -1;
			num -= 1;
			spin_gear_clock_or_counter(switch_val(num), dir);
		}
	}
}

void check_state()
{
	if (A[2] != B[6])
		state[0] = 1;
	else
		state[0] = 0;
	if (B[2] != C[6])
		state[1] = 1;
	else
		state[1] = 0;
	if (C[2] != D[6])
		state[2] = 1;
	else
		state[2] = 0;
}

int main()
{
	int K;
	int spin[101][101];
	int num, dir;
	int ans;

	std::cin >> a >> b >> c >> d;
	std::cin >> K;
	for (int i = 0 ; i < K ; i++)
		std::cin >> spin[i][0] >> spin[i][1];
	make_gear();
	for(int i = 0 ; i < K ; i++)
	{
		num = spin[i][0];
		dir = spin[i][1];
		check_state();
		spin_gear(num, dir);
	}

	ans = 0;
	if (A[0])
		ans +=1;
	if (B[0])
		ans +=2;
	if (C[0])
		ans += 4;
	if (D[0])
		ans += 8;

	printf("%d", ans);

	return (0);
}
