#1654
import sys

N, M = map(int,sys.stdin.readline().split())
li = [0] + list(map(int, sys.stdin.readline().split()))
for i in range(1, len(li)):
    li[i] = li[i - 1] + li[i]

for _ in range(M):
    a, b = map(int, sys.stdin.readline().split())
    print(li[b] - li[a - 1])
