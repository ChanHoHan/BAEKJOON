#include <iostream>
#include <cstring>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
int N, M;
int rel[102][102];

void input()
{
	int a, b;

	FASTIO;
	cin >> N >> M;
	memset(rel, 0x3f, sizeof(rel));
	for (int i = 0 ; i < M ; i++) {
		cin >> a >> b;
		rel[a][b] = 1;
		rel[b][a] = 1;
	}
}

void solve()
{
	for (int i = 1 ; i <= N ; i++) {
		for (int j = 1 ; j <= N ; j++) {
			for (int k = 1 ; k <= N ; k++) {
				if (rel[j][i] + rel[i][k] < rel[j][k])
					rel[j][k] = rel[j][i] + rel[i][k];
			}
		}
	}
	
	int min_ = 0;
	int ans = 1;

	for (int i = 2 ; i <= N ; i++) {
		min_ += rel[1][i];
	}
	for (int i = 2 ; i <= N ; i++) {
		int min_2 = 0;
		for (int j = 1 ; j <= N ; j++) {
			if (i == j)
				continue;
			min_2 += rel[i][j];
		}
		if (min_ > min_2) {
			ans = i;
			int tmp;
			tmp = min_;
			min_ = min_2;
			min_2 = tmp;
		}
	}
	cout << ans;
}

int main()
{
	input();
	solve();
	return (0);
}

