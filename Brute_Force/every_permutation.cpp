#include <iostream>
#include <vector>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
int N;
bool visited[9];

void input()
{
	FASTIO;
	cin >> N;
}

void dfs(vector<int> v, int cnt)
{
	if (cnt == N) {
		for (auto i: v)
		{
			cout << i << " " ;
		}
		cout << endl;
		return ;
	}
	for (int i = 1 ; i <= N ; i++)
	{
		if (visited[i]) continue;
		visited[i] = 1;
		v.push_back(i);
		dfs(v, cnt + 1);
		v.pop_back();
		visited[i] = 0;
	}
}

void solve()
{
	vector<int> v = {};
	dfs(v, 0);
}

int main()
{
	input();
	solve();
	return (0);
}
