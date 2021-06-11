#18290
import sys

N, M, K = map(int, sys.stdin.readline().split())
li = []
for _ in range(N):
    a = list(map(int, sys.stdin.readline().split()))
    li.append(a)

dy = (0, 0, 1, -1)
dx = (-1, 1, 0, 0)
visited = [[0 for _ in range(M)] for _ in range(N)]
max_ = -40001


def brute_force(y, x, depth, val):
    global max_

    if (depth == K):
        max_ = max(max_, val)
        return
    for i in range(y, N):
        for j in range(M):
            if (y == i and j <= x):
                continue
            for k in range(4):
                ny = dy[k] + i
                nx = dx[k] + j
                if (ny < 0 or ny >= N or nx < 0 or nx >= M):
                    continue
                if visited[ny][nx]:
                    break
            else:
                visited[i][j] = 1
                brute_force(i, j, depth + 1, val + li[i][j])
                visited[i][j] = 0

for i in range(N):
    for j in range(M):
        visited[i][j] = 1
        brute_force(i, j, 1, li[i][j])
        visited[i][j] = 0
print(max_)
