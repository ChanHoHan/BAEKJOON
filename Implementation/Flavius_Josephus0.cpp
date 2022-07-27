#include <iostream>
#include <queue>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"

queue<int> q;
int N, K;

void input()
{
	FASTIO;
	cin >> N >> K;
	for (int i = 1 ; i <= N ; i++)
		q.push(i);
}

void solve()
{
	cout << "<";
	while(!q.empty())
	{
		for (int i = 0 ; i < K - 1 ; i++)
		{
			int a = q.front();
			q.pop();
			q.push(a);
		}
		cout << q.front();
		q.pop();
		if (q.size() <= 0)
			break;
		cout << ", ";
	}
	cout << ">";
}

int main()
{
	input();
	solve();
	return (0);
}
