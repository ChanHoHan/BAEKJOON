import sys

g_map = []
N, M = map(int, sys.stdin.readline().split())
tmp = [[0 for _ in range(max(M, N))] for _ in range(max(M, N))]
for _ in range(N):
    a = list(map(int, sys.stdin.readline().split()))
    g_map.append(a)

def rotate_list():
    global N, M
    for j in range(M):
        for i in range(N - 1, -1, -1):
            tmp[j][N - 1 - i] = g_map[i][j]
    N,M = M,N


ans = 2 * N * M #밑, 위에서 볼 때

for _ in range(4):
    for j in range(M):
        prev = 0
        for i in range(N):
            if (g_map[i][j] > prev):
                ans += g_map[i][j] - prev
            prev = g_map[i][j]
    rotate_list() # 행렬 회전
    tmp, g_map = g_map, tmp

print(ans)