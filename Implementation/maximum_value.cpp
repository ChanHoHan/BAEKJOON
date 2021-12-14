#include <iostream>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"

void solve()
{
	int inp, num, max_value = -1;

	for (int i = 0 ; i < 9 ; i++)
	{
		cin >> inp;
		if (max_value < inp) {
			num = i + 1;
			max_value = inp;
		}
	}
	cout << max_value << endl << num;
}

int main()
{
	solve();
	return (0);
}
