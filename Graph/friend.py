import sys
from collections import deque

N = int(sys.stdin.readline().strip())
li = []
adj = [[] for _ in range(N)]
for _ in range(N):
    a = sys.stdin.readline().strip()
    li.append(a)
for i in range(N):
    for j in range(N):
        if (li[i][j] == 'Y'):
            adj[i].append(j)
            adj[j].append(i)

visited = [0 for _ in range(N)]
cnt = 0
ans = 0

for i in range(N):
    visited = [0 for _ in range(N)]
    visited[i] = 1
    q = deque()
    q.append((i, 0))
    cnt = 0
    while q:
        node, depth = q.popleft()
        for i in range(len(adj[node])):
            if (visited[adj[node][i]]):
                continue
            cnt+=1
            visited[adj[node][i]] = 1
            if (depth == 1):
                continue
            q.append((adj[node][i], depth+1))
    ans = max(ans, cnt)

print(ans)
