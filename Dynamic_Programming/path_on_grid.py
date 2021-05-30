#10164
import sys

N, M, K = map(int, sys.stdin.readline().split())
K -= 1

li = [[0 for _ in range(M)] for _ in range(N)]
K_c = int(K % M)
K_r = int(K / M)
if (K < 0):
    K_c = M - 1
    K_r = N - 1

for i in range(K_r + 1):
    for j in range(K_c + 1):
        if (i == 0 or j == 0):
            li[i][j] = 1
for i in range(1, K_r + 1):
    for j in range(1, K_c + 1):
        li[i][j] = (li[i - 1][j] + li[i][j - 1])
for i in range(K_r, N):
    for j in range(K_c, M):
        if (i == K_r or j == K_c):
            li[i][j] = li[K_r][K_c]
for i in range(K_r + 1, N):
    for j in range(K_c + 1, M):
        li[i][j] = (li[i - 1][j] + li[i][j - 1])
print(li[N-1][M-1])