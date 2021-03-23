#2178
import sys
from collections import deque

start_i = 1
start_j = 1
maze = [[0 for _ in range(102)] for _ in range(102)]
visited = [[0 for _ in range(102)] for _ in range(102)]
dx = [1, 0, -1, 0]
dy = [0, -1, 0, 1]
N,M = map(int, sys.stdin.readline().split())
for i in range(1, N+1):
	tmp = sys.stdin.readline()
	for j in range(1, M + 1):
		maze[i][j] = int(tmp[j - 1])
q = deque()
q.append((start_i, start_j, 1)) #i, j, distance
ans = 10003
while q:
    i, j, distance = q.popleft()
    if visited[i][j] == 1 or maze[i][j] == 0:
        continue
    if(i == N and j == M):
        if (ans > distance):
            ans = distance
    visited[i][j] = 1
    for x in range(4):
        q.append((i + dy[x] , j + dx[x], distance + 1))
print(ans)
