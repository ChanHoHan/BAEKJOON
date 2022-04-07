#include <iostream>
#include <string>
#include <queue>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"

int R, C;
string g_map[501];
queue<pair<int, int> > q, a_q;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

void input()
{
	FASTIO;
	cin >> R >> C;
	for (int i = 0 ; i < R ; i++) {
		cin >> g_map[i];
		for (int j = 0 ; j < C ; j++) {
			if (g_map[i][j] == 'W') {
				q.push({i, j});
			}
			else {
				a_q.push({i, j});
			}
		}
	}
}

void solve()
{
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0 ; i < 4 ; i++) {
			int ny = dy[i] + y;
			int nx = dx[i] + x;
			if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
			if (g_map[ny][nx] == 'S') {
				cout << 0 ;
				return ;
			}
		}
	}
	cout << 1 << endl;
	while (!a_q.empty()) {
		int y = a_q.front().first;
		int x = a_q.front().second;
		a_q.pop();
		for (int i = 0 ; i < 4 ; i++) {
			int ny = dy[i] + y;
			int nx = dx[i] + x;
			if (ny < 0 || ny >= R || nx < 0 || nx >= C || g_map[ny][nx] == 'S' || g_map[ny][nx] == 'D' || g_map[ny][nx] == 'W')  continue;
			g_map[ny][nx] = 'D';
			
		}
	}
	for (int i = 0 ; i < R ; i++)
	{
		for (int j = 0 ; j < C ; j++) {
			cout << g_map[i][j];
		}
		cout << endl;
	}
}

int main()
{
	input();
	solve();
	return (0);
}

