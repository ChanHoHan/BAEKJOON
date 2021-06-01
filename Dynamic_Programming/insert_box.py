#1965
import sys

n = int(sys.stdin.readline())
li = list(map(int, sys.stdin.readline().split()))
dp = [1 for _ in range(n)]
for i in range(n):
    for j in range(i):
        if (dp[i] <= dp[j] and li[i] > li[j]):
            dp[i] = dp[j] + 1
print(sorted(dp)[-1])