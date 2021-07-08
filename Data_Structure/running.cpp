//2517
#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"

typedef std::pair<int, int> pii;

int N;
pii player[500001];
int tr[1<<20];

int seg_sum(int node, int s, int e, int l, int r)
{
	if (r < s || e < l)
		return (0);
	if (l <= s && e <= r)
		return (tr[node]);
	else
		return (seg_sum(node * 2, s, (s + e) / 2 , l , r) + seg_sum(node * 2 + 1 , (s + e) / 2 + 1 , e, l , r));
}

void update(int node, int s, int e, int idx, int v)
{
	if (idx < s || e < idx)
		return;
	if (s == e)
	{
		tr[node] = v;
	}
	else
	{
		update(node * 2, s, (s + e) / 2, idx, v);
		update(node * 2 + 1, (s + e) / 2 + 1, e, idx, v);
		tr[node] = tr[node * 2] + tr[node * 2 + 1];
	}
}

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

bool compare(pii a, pii b)
{
	return (a.second < b.second);
}

void input()
{
	int power;

	io_faster();
	std::cin >> N;
	for (int i = 0 ; i < N ; i++)
	{
		std::cin >> power;
		player[i].first = i;
		player[i].second = power;
	}
}

void solve()
{
	int num = 0;
	std::sort(player, player + N, compare);
	//re label
	for (int i = 0 ; i < N ; i++)
	{
		player[i].second = ++num;
	}

	std::sort(player, player + N);
	for (int i = 0 ; i < N ; i++)
	{
		int curpower = player[i].second;
		int count = 0;
		if (curpower >= 1)
			count = seg_sum(1, 1, num, 1, curpower - 1);
		update(1, 1, num, curpower, 1);
		std::cout << i + 1 - count << endl;
	}

}

int main()
{
	input();
	solve();
	return (0);
}
