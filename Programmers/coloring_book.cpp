#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

bool visited[101][101];
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

void bfs(int y, int x, int m, int n, std::vector<std::vector<int> >&picture, int &max_size)
{
    int ny, nx, qy, qx, cnt = 0, color;
    
    visited[y][x] = 1;
    color = picture[y][x];
    std::queue<std::pair<int, int> >q;
    cnt++;
    q.push({y, x});
    
    while(!q.empty())
    {
        qy = q.front().first;
        qx = q.front().second;
        q.pop();
        for (int i = 0 ; i < 4 ; i++)
        {
            ny = qy + dy[i];
            nx = qx + dx[i];
            if (ny < 0 || ny >= m || nx < 0 || nx >= n || visited[ny][nx] || picture[ny][nx] != color)
                continue;
            visited[ny][nx] = 1;
            q.push({ny, nx});
            cnt++;
        }
    }
    max_size = std::max(max_size, cnt);    
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
std::vector<int> solution(int m, int n, std::vector<std::vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    std::memset(visited, 0, sizeof(visited));

    for (int i = 0 ; i < m ; i++)
        for (int j = 0 ; j < n ; j++)
            if (!visited[i][j] && picture[i][j])
            {
                bfs(i, j, m, n, picture, max_size_of_one_area);
                number_of_area++;
            }
    std::vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
