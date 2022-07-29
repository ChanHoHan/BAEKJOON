#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
int V;
vector<pair<int, int> >v[100002]; // next vertex, cost
bool visited[100002];

int max_v = -1, max_dist = -1;

void input()
{
	FASTIO;
    cin >> V;
    for (int i = 0 ; i < V ; i++)  
    {
        int vertex, tmp, b;
        
        cin >> vertex;

        while(true)
        {
            cin >> tmp;
            if (tmp == -1) break;
            cin >> b;
            v[vertex].push_back(make_pair(tmp, b));
        }
    }
}

void dfs(int va, int co)
{
    if (visited[va]) return;
    visited[va] = 1;
    int size = v[va].size();
    for (int i = 0 ; i < size ; i++)
    {
        int next = v[va][i].first;
        int cost = v[va][i].second;
        if (visited[next]) continue;
        if (max_dist < cost + co)
        {
            max_v = next;
            max_dist = cost + co;
        }
        dfs(next, cost + co);
    }
    visited[va] = 0;
}

void solve()
{
    dfs(1, 0);
    memset(visited, 0 , sizeof(visited));
    dfs(max_v, 0);
    cout << max_dist;
}

int main()
{
	input();
	solve();
	return (0);
}
