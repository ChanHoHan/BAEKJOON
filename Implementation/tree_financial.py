import sys
from collections import deque
import copy

dy = [-1, -1, -1, 0, 0, 1, 1, 1]
dx = [-1, 0, 1, -1, 1, -1, 0, 1]
def spring(tree_info, g_map, q):
    for i in range(1, len(tree_info)):
        for j in range(1, len(tree_info[i])):
            if (len(tree_info[i][j])):
                tree_info[i][j].sort()
                for k in range(len(tree_info[i][j])):
                    age = tree_info[i][j][k]
                    if (age <= g_map[i][j]): # 양분을 먹는다면
                        g_map[i][j] -= age
                        tree_info[i][j][k] += 1
                    else: # 죽는다면
                        for l in range(k, len(tree_info[i][j])):
                            q.append((i, j, tree_info[i][j][l]))
                        del tree_info[i][j][k:]
                        break
def summer(q, g_map):
    while q:
        y, x, age = q.popleft()
        g_map[y][x] += (age // 2)

def fall(tree_info, N):
    global dy, dx
    for i in range(1, len(tree_info)):
        for j in range(1, len(tree_info[i])):
            if not (len(tree_info[i][j])):
                continue
            for k in range(len(tree_info[i][j])):
                if not (tree_info[i][j][k] % 5): # 5의 배수이면
                    for l in range(len(dx)):
                        ny = i + dy[l]
                        nx = j + dx[l]
                        if (ny <= 0 or ny > N or nx <= 0 or nx > N):
                            continue
                        tree_info[ny][nx].append(1)


def winter(A, g_map):
    for i in range(1, len(g_map)):
        for j in range(1, len(g_map[i])):
            g_map[i][j] += A[i - 1][j]

N, M, K = map(int, sys.stdin.readline().split())
g_map = [[5 for _ in range(N + 1)] for _ in range(N + 1)]
A = []
tree_info = [[[] for _ in range(N + 1)] for _ in range(N + 1)]
for i in range(N):
    A.append([0] + list(map(int, sys.stdin.readline().split())))
for i in range(M):
    li = list(map(int, sys.stdin.readline().split()))
    y, x, z = li[0], li[1], li[2]
    tree_info[y][x].append(z)

q = deque()


while (K):
    spring(tree_info, g_map, q)
    summer(q, g_map)
    fall(tree_info, N)
    winter(A, g_map)
    K-=1

ans = 0
for i in range(1, len(tree_info)):
    for j in range(1, len(tree_info[i])):
        ans += len(tree_info[i][j])
print(ans)