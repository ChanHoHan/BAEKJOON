#include <string>
#include <vector>
#include <set>

using namespace std;

int max_ = 1;

void dfs(vector<int> &info, vector<vector<int> >& edges, int node, int n_sheep, int n_wolf, vector<int> go)
{
	
    for (size_t i = 0 ; i < go.size() ; i++)
    {
        int next_node = go[i];
        int next_sheep = n_sheep;
        int next_wolf = n_wolf;
        if (!info[next_node]) next_sheep++;
        else next_wolf++;
        if (next_sheep <= next_wolf) continue;
        if (max_ < next_sheep) max_ = next_sheep;
        set<int> save;
        for (size_t j = 0 ; j < go.size() ; j++) {
            if (i == j) continue;
            save.insert(go[j]);
        }
        for (size_t j = 0 ; j < edges[next_node].size() ; j++)
        {
            if (node == edges[next_node][j]) continue;
            save.insert(edges[next_node][j]);
        }
        vector<int> v(save.begin(), save.end());
        dfs(info, edges, next_node, next_sheep, next_wolf, v);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    vector<vector<int> >v(18, vector<int>());
    for (size_t i = 0 ; i < edges.size() ; i++)
        v[edges[i][0]].push_back(edges[i][1]);
    vector<int> save;
    for (size_t i = 0 ; i < v[0].size() ; i++)
        save.push_back(v[0][i]);
    dfs(info, v, 0, 1, 0, save);
    return max_;
}
