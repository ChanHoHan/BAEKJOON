import sys

N = int(sys.stdin.readline())
li = []
for _ in range(N):
    tmp = list(map(int, sys.stdin.readline().split()))
    li.append(tmp)
g_map = [[0 for _ in range(100)] for _ in range(100)]

for item in li:
    y, x = item
    for i in range(y, y + 10):
        for j in range(x, x + 10):
            if (not g_map[i][j]):
                g_map[i][j] = 1

cnt = 0
for i in range(100):
    for j in range(100):
        if (g_map[i][j]):
            cnt+=1
print(cnt)