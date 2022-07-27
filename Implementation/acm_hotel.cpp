#include <cstring>
#include <iostream>
#include <string>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"

int T, H, W, N;

void input()
{
	FASTIO;
	cin >> T;
}

void solve()
{
	while(T--) 
	{
		cin >> H >> W >> N;
		string prefix = to_string((N - 1) % H + 1);
		string suffix = to_string((N - 1) / H + 1);
		if (suffix.length() == 1) suffix = "0" + suffix;
		cout << prefix + suffix << endl;
	}

}

int main()
{
	input();
	solve();
	return (0);
}
