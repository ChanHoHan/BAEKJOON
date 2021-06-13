#1497
import sys

N, M = map(int, sys.stdin.readline().split())
ans = 11
max_val = 0
songs = [[] for _ in range(M)]
g_play = []

for _ in range(N):
    guitar, s = sys.stdin.readline().split()
    val = 0
    for i in range(M):
        if (s[i] == 'Y'):
            val += pow(2, M - i - 1)
    g_play.append(val)

def brute_force(ind, cnt, visited):
    global ans, max_val

    count = 0
    tmp = 1
    while (tmp <= ((1 << M) - 1)):
        if (tmp & visited):
            count += 1
        tmp *= 2
    if (count > max_val):
        ans = cnt
        max_val = count
    elif (count == max_val):
        ans = min(ans, cnt)

    if (ind >= N):
        return

    for i in range(ind, N):
        if (visited == (visited | g_play[i])):
            continue
        brute_force(i + 1, cnt + 1, visited | g_play[i])

for i in range(N):
    brute_force(i + 1, 1, g_play[i])

if (max_val == 0):
    print(-1)
else:
    print(ans)
