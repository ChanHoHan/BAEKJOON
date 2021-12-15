#include <iostream>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
int N;
int min_value = 1111111, max_value = -1111111;

void input()
{
	FASTIO;
	cin >> N;
}

void solve()
{
	int tmp;

	for (int i = 0 ; i < N ; i++)
	{
		cin >> tmp;
		min_value = min_value > tmp ? tmp : min_value;
		max_value = max_value < tmp ? tmp : max_value;
	}
	cout << min_value << " " << max_value;
}

int main()
{
	input();
	solve();
	return (0);
}

