import sys

A, B = map(int, sys.stdin.readline().split())
ans = int(1e9) + 1
def dfs(val, depth):
    global B, ans

    if (val > int(1e9)):
        return
    if (val == B):
        ans = min(ans, depth + 1)
        return
    dfs(val * 2, depth + 1)
    dfs(10 * val + 1, depth + 1)

dfs(A, 0)
if (ans == int(1e9) + 1):
    print(-1)
else:
    print(ans)