#10211
import sys

T = int(sys.stdin.readline())

for _ in range(T):
    N = int(sys.stdin.readline())
    li = list(map(int, sys.stdin.readline().split()))
    for i in range(1, N):
        li[i] = max(li[i - 1] + li[i], li[i])
    print(sorted(li)[-1])
