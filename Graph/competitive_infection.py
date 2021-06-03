#18405
import sys
from collections import deque

N, K = map(int, sys.stdin.readline().split())
li = []
save = [[] for _ in range(K + 1)]
for _ in range(N):
    x = list(map(int, sys.stdin.readline().split()))
    li.append(x)
for i in range(N):
    for j in range(N):
        if (li[i][j] != 0):
            save[li[i][j]].append((i,j))
S,Y,X = map(int, sys.stdin.readline().split())
dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]
ans = 0
q = deque()

for i in range(1, K + 1):
    if (len(save[i])):
        for j in range(len(save[i])):
            a,b = save[i][j]
            q.append((a, b, S, i))
while (q):
    qy, qx, s_val, inp_val = q.popleft()
    if (s_val == 0):
        break
    for i in range(4):
        ny = qy + dy[i]
        nx = qx + dx[i]
        if (ny < 0 or ny >= N or nx < 0 or nx >= N or li[ny][nx]):
            continue
        li[ny][nx] = inp_val
        q.append((ny, nx, S - 1, inp_val))

print(li[Y-1][X-1])
