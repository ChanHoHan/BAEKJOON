//1713
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int N, R;
std::queue<int> q;
int students[101];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

void input()
{
	io_faster();
	std::cin >> N >> R;
}

void remove_op()
{
	int cnt = N, num, remove_snum, max_val = 1002;

	while (cnt--)
	{
		num = q.front();
		q.pop();
		if (max_val > students[num])
		{
			max_val = students[num];
			remove_snum = num;
		}
		q.push(num);
	}
	cnt = N;
	while (cnt--)
	{
		num = q.front();
		q.pop();
		if (num != remove_snum)
			q.push(num);
	}
	students[remove_snum] = -1;
}

void solve()
{
	int num;

	for (int i = 0 ; i < 101 ; i++)
		students[i] = -1;
	for (int i = 0 ; i < R ; i++)
	{
		std::cin >> num;
		if (students[num] == -1)
		{
			if ((int)q.size() == N)
				remove_op();
			students[num] = 1;
			q.push(num);
		}
		else
			students[num]  += 1;
	}
	std::vector <int> ans;
	while (!q.empty())
	{
		ans.push_back(q.front());
		q.pop();
	}
	std::sort(ans.begin(), ans.end());
	for (size_t i = 0 ; i < ans.size() ; i++)
		std::cout << ans[i] << " " ;
}

int main()
{
	input();
	solve();
	return (0);
}
