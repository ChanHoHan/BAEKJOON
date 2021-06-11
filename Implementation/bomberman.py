#16918
import sys

R, C, N = map(int, sys.stdin.readline().split())
g_map = [sys.stdin.readline().strip() for i in range(R)]
second_map = [['O' for _ in range(C)] for _ in range(R)]
third_map = [['O' for _ in range(C)] for _ in range(R)]
dx = (0, 0, 1, -1)
dy = (1, -1, 0, 0)
for i in range(R):
    for j in range(C):
        if (g_map[i][j] == 'O'):
            second_map[i][j] = '.'
            for k in range(4):
                ny = dy[k] + i
                nx = dx[k] + j
                if (ny < 0 or ny >= R or nx < 0 or nx >= C or second_map[ny][nx] == '.'):
                    continue
                second_map[ny][nx] = '.'


for i in range(R):
    for j in range(C):
        if (second_map[i][j] == 'O'):
            third_map[i][j] = '.'
            for k in range(4):
                ny = dy[k] + i
                nx = dx[k] + j
                if (ny < 0 or ny >= R or nx < 0 or nx >= C or third_map[ny][nx] == '.'):
                    continue
                third_map[ny][nx] = '.'
def print_map(li):
    for i in li:
        for j in i:
            print(j, end="")
        print()

if (N == 1):
    print_map(g_map)
    exit(0)

if (not N % 2):
    li = [['O' for _ in range(C)] for _ in range(R)]
    for i in li:
        for j in i:
            print(j, end="")
        print()
    exit(0)

if (N % 4 == 1):
    print_map(third_map)
elif (N % 4 == 3):
    print_map(second_map)
