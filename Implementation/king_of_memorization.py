#2776
import sys
T = int(sys.stdin.readline().strip())
for _ in range(T):
    N = int(sys.stdin.readline().strip())
    s1 = set(map(int, sys.stdin.readline().split()))
    M = int(sys.stdin.readline().strip())
    s2 = list(map(int, sys.stdin.readline().split()))
    for i in range(M):
        if s2[i] in s1:
            print(1)
        else:
            print(0)
