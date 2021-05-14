import sys

N = int(sys.stdin.readline())
li = []
for i in range(N):
    li.append(sys.stdin.readline().strip())
ans = ""
for j in range(len(li[0])):
    for i in range(N - 1):
        if li[i][j] != li[i + 1][j]:
            ans += "?"
            break
    else:
        ans += li[0][j]
print(ans)