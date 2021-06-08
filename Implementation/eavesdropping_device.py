#9319
import sys

T = int(sys.stdin.readline().strip())

def dist(y1, x1, y2, x2):
    return ((y2 - y1) ** 2 + (x2 - x1) ** 2)

def is_correct(r, val):
    if (r / 6 - val > 0):
        return (1)
    return (0)

while T:
    n = int(sys.stdin.readline().strip())
    B = int(sys.stdin.readline().strip())
    x, y = map(int, sys.stdin.readline().split())
    li = []
    ans = []
    for i in range(1, n + 1):
        a = list(map(int, sys.stdin.readline().split()))
        li.append(a)
    r = [0]
    cnt = 0
    for i in range(n):
        x1, y1, s = li[i]
        r_tmp = s / (dist(y,x,y1,x1))
        r.append(r_tmp)
        cnt += r_tmp
    for i in range(1, n + 1):
        val = B + cnt - r[i]
        if (is_correct(r[i], val)):
            ans.append(i)
    if (not len(ans)):
        print("NOISE")
    else:
        for i in range(len(ans)):
            print(ans[i], end=" ")
    T-=1
