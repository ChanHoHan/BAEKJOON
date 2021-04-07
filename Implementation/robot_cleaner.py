import sys

N, M = map(int, input().split())
r, c, d = map(int, input().split())
dy = [-1, 0, 1, 0] #NESW
dx = [0, 1, 0, -1]
g_map = []
ans = 0
for i in range(N):
    g_map.append(list(map(int, sys.stdin.readline().split())))
visited = [[1 for _ in range(M)] for _ in range(N)]

def get_left_index(d):
    return (d + 3) % 4

def get_back_index(d):
    return (d + 2) % 4

def operation(depth):
    global r, c, d, N, M, ans
    if (visited[r][c]):
        visited[r][c] = 0 #1
        ans += 1
    if (depth == 4):
        back_index = get_back_index(d)
        r += dy[back_index]
        c += dx[back_index]
        if (r < 0 or r >= N or c < 0 or c >= M or g_map[r][c]):
            return (0)
        return (1)
    d = get_left_index(d)
    ny = r + dy[d]
    nx = c + dx[d]
    if (ny < 0 or ny >= N or nx < 0 or nx >= M or g_map[ny][nx] or not visited[ny][nx]):
        return(operation(depth + 1))
    r = ny
    c = nx
    return (1)

while (operation(0)):
    pass
print(ans)
