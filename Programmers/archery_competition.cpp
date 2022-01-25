#include <string>
#include <vector>
#include <iostream>
using namespace std;    
vector<int> answer = {-1};
int ans_sum = -1;

void dfs(vector<int>& info, vector<int> ans, int info_total, int n, int index, int ans_total) {
    if (n == 0 || index < 0) {
        if (info_total < ans_total && ans_sum <= ans_total - info_total) {
            ans[10] += n;
            if (ans_sum == ans_total - info_total && answer.size() != 1) {
                for (int i = 10 ; i >= 0 ; i--) {
                    if (answer[i] > ans[i])
                        return;
                    if (answer[i] < ans[i])
                        break;
                }
            }
            answer = ans;
            ans_sum = ans_total - info_total;
        }
        return ;
    }
    dfs(info, ans, info_total, n, index - 1, ans_total);
    if (n > info[index]) {
        ans[index] = info[index] + 1;
        n -= ans[index];
        ans_total += (10 - index);
        if (info[index])
            info_total -= (10 - index);
        dfs(info, ans, info_total, n, index - 1, ans_total);
    } 
}

vector<int> solution(int n, vector<int> info) {
    int total = 0;

    for (int i = 0 ; i <= 10 ; i++) {
        if (info[i]) total += (10 - i);
    }
    dfs(info, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, total, n, 10, 0);
    return answer;
}
