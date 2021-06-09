#2841
import sys
from collections import deque

N, P = map(int, sys.stdin.readline().split())
li = [deque() for _ in range(7)]
ans = 0
for _ in range(N):
    a,b = map(int, sys.stdin.readline().split())
    c = -1
    if li[a]:
        while li[a]:
            c = li[a].pop()
            ans+=1
            if (b >= c):
                ans-=1
                li[a].append(c)
                break
    if (b == c):
        continue
    ans+=1
    li[a].append(b)
print(ans)
