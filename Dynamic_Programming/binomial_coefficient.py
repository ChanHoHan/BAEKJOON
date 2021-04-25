import sys

N, K = map(int, sys.stdin.readline().split())
dp = [[0 for _ in range(N + 1)] for _ in range(N + 1)]
def combination(n, k):
    if (n == k or k == 0):
        return 1
    if dp[n][k]:
        return dp[n][k]
    dp[n][k] = combination(n - 1, k) + combination(n - 1, k - 1)
    return dp[n][k]

print(combination(N, K) % 10007)
