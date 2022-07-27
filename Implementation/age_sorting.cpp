#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
typedef pair<int, pair<int, string> > t;

int N;
vector<t> v;

void input()
{
	int n;
	string name;

	FASTIO;
	cin >> N;
	for (int i = 0 ; i < N ; i++)
	{
		cin >> n >> name;
		v.push_back({i, {n, name}});
	}
}

bool compare(t a, t b)
{
	if (a.second.first < b.second.first)
		return a.second.first < b.second.first;
	else {
		if (a.second.first >= b.second.first)
			return false;
		return true;
	}
}

void solve()
{
	stable_sort(v.begin(), v.end(), compare);
	for(t vec : v)
		cout << vec.second.first << " " << vec.second.second << endl;
}

int main()
{
	input();
	solve();
	return (0);
}

