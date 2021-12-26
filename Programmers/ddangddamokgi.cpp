#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0, row = land.size();
    
    for (int i = 1 ; i < row ; i++) {
        for (int j = 0 ; j < 4 ; j++) {
            int max_val = -1;
            for (int k = 0 ; k < 4 ; k++) {
                if (k == j) continue;
                if (max_val < land[i - 1][k]) max_val = land[i - 1][k];
            }
            land[i][j] += max_val;
        }
    }
    answer = max({land[row - 1][0], land[row - 1][1], land[row - 1][2], land[row - 1][3]});
    return answer;
}
