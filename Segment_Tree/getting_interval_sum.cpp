//2042
#include <iostream>
#define endl "\n"

typedef long long ll;
int N, M, K;
ll table[1<<21];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

ll get_sum(int node, int s, int e, int l, int r)
{
	if (r < s || e < l)
		return (0);
	if (l <= s && e <= r)
		return (table[node]);
	else
		return (get_sum(node * 2, s, (s + e) / 2, l, r) + get_sum(node * 2 + 1, (s + e) / 2 + 1, e, l, r));
}

void update(int node, int s, int e, int idx, ll val)
{
	if (idx < s || e < idx)
		return;
	if (s == e)
	{
		table[node] = val;
	}
	else
	{
		update(node * 2 , s, (s + e) / 2, idx, val);
		update(node * 2 + 1, (s + e) / 2 + 1, e, idx, val);
		table[node] = table[node * 2] + table[node * 2 + 1];
	}
}

void solve()
{
	ll a, b, c;

	io_faster();
	std::cin >> N >> M >> K;
	for (int i = 1 ; i <= N ; i++)
	{
		std::cin >> a;
		update(1, 1, N, i, a);
	}
	for (int i = 0 ; i < M + K ; i++)
	{
		std::cin >> a >> b >> c;
		if (a == 1)
			update(1, 1, N, b, c);
		else if (a == 2)
			std::cout << get_sum(1, 1, N, b, c) << endl;
	}

}

int main()
{
	solve();
	return (0);
}
