//17140
#include <iostream>
#include <algorithm>
#include <queue>

int r, c, k;
int a[101][101];
int now_r, now_c;
std::priority_queue<int> val[101]; // 해당 갯수에 들어가 있는 숫자
int tmp[101];

void input_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	int x;

	input_faster();
	std::cin >> r >> c >> k;
	for (int i = 1 ; i <= 3 ; i++)
		for (int j = 1 ; j <= 3 ; j++)
			std::cin >> a[i][j];
	now_r = 3;
	now_c = 3;
}

void input_priority_q(int point, int index)
{
	val[index].push(point);
}

void R_operation()
{
	int point, cnt;

	for (int i = 1 ; i <= now_r ; i++)
	{
		//first. sorting
		std::sort(a[now_r], a[now_r] + now_c);
		//second. 갯수 count
		point = a[i][1];
		cnt = 1;
		for (int j = 2 ; j <= now_c ; j++)
		{
			if (point != a[i][j])
			{
				input_priority_q(point, cnt);
				point = a[i][j];
				cnt = 1;
			}
			else
				cnt++;
		}
		input_priority_q(point, cnt);
	}
}

void cpy_col(int j)
{
	for (int i = 1 ; i <= now_r ; i++)
		tmp[i] = a[i][j];
}

void C_operation()
{
	int point, cnt;

	for (int j = 1 ; j <= now_c ; j++)
	{
		cpy_col(j);
		std::sort(tmp + 1, tmp + now_c + 1);
		point = a[1][j];
		cnt = 1;
		for (int i = 2 ; i <= now_r ; i++)
		{
			if (point != a[i][j])
			{
				input_priority_q(point, cnt);
				point = a[i][j];
				cnt = 1;
			}
			else
				cnt++;
		}
		input_priority_q(point, cnt);
	}
}

void solve()
{

}

int main()
{
	input();
	solve();
	return (0);
}

