#11000

import sys
import heapq

N = int(input())
li = []
for _ in range(N):
    a, b = map(int,sys.stdin.readline().split())
    li.append([a, b])
li.sort()
h = []

for i in li:
    a, b = i
    if not len(h):
        heapq.heappush(h, b)
    else:
        if (a < h[0]):
            heapq.heappush(h, b)
        else:
            heapq.heappop(h)
            heapq.heappush(h, b)
print(len(h))
