#include <iostream>
#include <cmath>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
int M, N;
bool era[1000003];

void input()
{
	FASTIO;
	cin >> M >> N;
}

void fill_era() 
{
	era[0] = true;
	era[1] = true;
	for (int i = 2 ; i <= N ; i++)
	{
		if (era[i]) continue;
		int j = 2;
		while (i * j <= N)
			era[i * j++] = true;
	}
}

void solve()
{
	fill_era();
	for (int i = M ; i <= N ; i++)
		if (!era[i]) cout << i << endl;
}

int main()
{
	input();
	solve();
	return (0);
}
