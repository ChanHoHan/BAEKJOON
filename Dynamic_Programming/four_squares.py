n = int(input())
s = set()
for i in range(300):
    s.add(i * i)

dp = [99999999 for _ in range(n + 1)]
for i in range(1, n + 1):
    if i in s:
        dp[i] = 1
    else:
        j = 1
        while (True):
            if (i <= j * j):
                break
            dp[i] = min(dp[i], dp[i - j * j] + 1)
            j+=1
print(dp[n])