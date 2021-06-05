import sys

M, N = map(int, sys.stdin.readline().split())
li = []
dx = [0,0,1,-1]
dy = [1,-1,0,0]
cnt = 0

power = [0, 0]
team = dict()
team['W'] = 0
team['B'] = 1

visited = [[0 for _ in range(M + 1)] for _ in range(N + 1)]

def dfs(y, x, color):
    global cnt

    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if (ny < 0 or ny >= N or nx < 0 or nx >= M or li[ny][nx] != color or visited[ny][nx]):
            continue
        visited[ny][nx] = 1
        cnt += 1
        dfs(ny, nx, color)

for _ in range(N):
    k = sys.stdin.readline().rstrip()
    li.append(k)

for i in range(N):
    for j in range(M):
        if (not visited[i][j]):
            cnt = 0
            dfs(i, j, li[i][j])
            if (not cnt):
                cnt = 1
            power[team[li[i][j]]] += (cnt ** 2)

print(power[0], power[1])
