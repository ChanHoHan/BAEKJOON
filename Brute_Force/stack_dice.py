#2116
import sys
N = int(sys.stdin.readline())
li = [[]]
next = [0, 5, 3, 4, 1, 2, 0]
ans = 0
for _ in range(N):
    a = list(map(int, sys.stdin.readline().split()))
    li.append(a)

for i in range(6):
    next_val = li[1][i]
    depth = 1
    max_ = 0

    while(True):
        val = next_val
        if (depth == N + 1):
            ans = max(ans, max_)
            break
        for j in range(len(li[depth])):
            if (li[depth][j] == val):
                next_val = li[depth][next[j + 1]]
        for j in reversed(range(1, 7)):
            if (j != next_val and j != val):
                max_ += j
                break
        depth+=1

print(ans)
