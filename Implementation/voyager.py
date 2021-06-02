import sys

N, M = map(int, sys.stdin.readline().split())
li = []
dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

for _ in range(N):
    a = sys.stdin.readline().rstrip()
    li.append(a)
PR, PC = map(int, sys.stdin.readline().split())
PR-=1
PC-=1

val = 0
cnt = 0
direction = 0
index_i = PR
index_j = PC
visited = [[[0 for _ in range(501)] for _ in range(501)] for _ in range(4)]

slash = dict()
slash[0] = 1
slash[1] = 0
slash[2] = 3
slash[3] = 2

not_slash = dict()
not_slash[0] = 3
not_slash[1] = 2
not_slash[2] = 1
not_slash[3] = 0

ans = ['U', 'R', 'D', 'L']
ans_dir = 0
def cal():
    global index_i
    global index_j
    global cnt
    global direction
    while(True):
        ny = index_i + dy[direction]
        nx = index_j + dx[direction]
        cnt += 1
        if (visited[direction][ny][nx]):
            return 4
        if (ny < 0 or ny >= N or nx < 0 or nx >= M or li[ny][nx] == 'C'):
            return 5
        index_i = ny
        index_j = nx
        visited[direction][ny][nx] = 1
        if (li[ny][nx] == '\\'):
            direction = not_slash[direction]
        elif (li[ny][nx] == '/'):
            direction = slash[direction]

for i in range(4):
    direction = i
    index_i = PR
    index_j = PC
    cnt = 0
    visited = [[[0 for _ in range(501)] for _ in range(501)] for _ in range(4)]
    tmp = cal()
    if (tmp == 4):
        print(ans[i])
        print("Voyager")
        exit(0)
    if (tmp == 5):
        if (val < cnt):
            val = cnt
            ans_dir = i
print(ans[ans_dir])
print(val)