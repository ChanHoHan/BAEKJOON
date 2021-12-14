#include <iostream>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"

string ans[3] = {"ascending", "descending", "mixed"};

void input()
{
	FASTIO;
}

int solve()
{
	int a, b;

	cin >> a >> b;
	int sub = b - a;
	if (sub != 1 && sub != -1)
		return 2;
	for (int i = 0 ; i < 6 ; i++)
	{
		cin >> a;
		if (a - b != sub)
			return 2;
		b = a;
	}
	return (sub == -1 ? 1 : 0);
}

int main()
{
	input();
	cout << ans[solve()];
	return (0);
}
