//14003
#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"

typedef std::pair<int, int> pii;

int N;
int seg[1<<21];
pii inp[1000001];
int original[1000001];
int res[1<<21];

void io_faster()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
}

int query(int node, int s, int e, int l, int r)
{
	if (e < l || r < s)
		return (0);
	if (l <= s && e <= r)
		return (seg[node]);
	return (std::max(query(node * 2, s, (s + e) / 2, l, r), query(node * 2 + 1, (s + e) / 2 + 1, e, l, r)));
}

void update(int node, int s, int e, int idx, int val)
{
	if (idx < s || e < idx)
		return ;
	if (s == e)
	{
		seg[node] = std::max(seg[node], val);
	}
	else
	{
		update(node * 2, s, (s + e) / 2, idx, val);
		update(node * 2 + 1, (s + e) / 2 + 1, e, idx, val);
		seg[node] = std::max(val, seg[node]);
	}
}

void input()
{
	int a;

	io_faster();
	std::cin >> N;
	for (int i = 1 ; i <= N ; i++)
	{
		std::cin >> a;
		inp[i].first = a;
		inp[i].second = i;
		original[i] = a;
	}
}
bool compare(pii a, pii b)
{
	if (a.first == b.first)
		return (a.second > b.second);
	return (a.first < b.first);
}

void solve()
{
	int a, ans_ind = 0, ans = 0, q_result, ind;
	std::vector<int> result;
	std::sort(inp, inp + N + 1, compare);
	for (int i = 1 ; i <= N ; i++)
	{
		a = inp[i].first;
		ind = inp[i].second;
		q_result = query(1, 1, N, 1, ind - 1) + 1;
		update(1, 1, N, ind, q_result);
		res[ind] = q_result;
		if (ans < q_result)
		{
			ans = q_result;
			ans_ind = i;
		}
	}
	int cnt = ans;
	int ret = 1000000005;
	
	for (int i = N ; i >= 1 ; i--)
	{
		if (res[i] == cnt && original[i] < ret)
		{
			cnt--;
			result.push_back(original[i]);
			ret = original[i];
		}
	}
	std::sort(result.begin(), result.end());
	std::cout << result.size() << endl;
	for (size_t i = 0 ; i < result.size() ; i++)
		std::cout << result[i] << " ";
}

int main()
{
	input();
	solve();
	return (0);
}

