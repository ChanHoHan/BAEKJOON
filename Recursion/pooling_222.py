#17829
import sys

N = int(sys.stdin.readline())
li = []
for _ in range(N):
    b = list(map(int, sys.stdin.readline().split()))
    li.append(b)

def dc(y, x, l):
    if (l == 1):
        return (li[y][x])
    li_ = [dc(y, x, l//2), dc(y + l//2, x, l//2), dc(y, x + l//2, l//2), dc(y + l//2, x + l//2, l//2)]
    li_.sort()
    return (li_[-2])

print(dc(0, 0, N))