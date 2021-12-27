#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define _MAX 999999999

int visited[51], answer;
vector<pair<int, int> > v[51];

void dfs(int node, int now_cost, int& K)
{
    int size = v[node].size();
    for (int i = 0 ; i < size ; i++) {
        int next = v[node][i].first;
        int cost = v[node][i].second;
        
        if (visited[next] > now_cost + cost && now_cost + cost <= K) {
            visited[next] = now_cost + cost;
            dfs(next, now_cost + cost, K);
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    fill(visited, visited + 51, _MAX);
    for (size_t i = 0 ; i < road.size() ; i++) {
        v[road[i][0]].push_back({road[i][1],road[i][2]});
        v[road[i][1]].push_back({road[i][0], road[i][2]});
    }
    visited[1] = 0;
    dfs(1, 0, K);
    for (int i = 0 ; i < 51 ; i++)
    {
        if (visited[i] != _MAX) answer++;
    }

    return answer;
}
