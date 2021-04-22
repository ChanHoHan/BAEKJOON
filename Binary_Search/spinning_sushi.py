#2531
import sys

N, d, k, c = map(int, sys.stdin.readline().split())
belt = []
sushi = dict()
for _ in range(N):
    a = int(sys.stdin.readline())
    belt.append(a)
for i in range(N):
    belt.append(belt[i])
left = 0
right = k - 2
for i in range(right + 1):
    if (belt[i] in sushi):
        sushi[belt[i]] += 1
    else:
        sushi[belt[i]] = 1
ans = 0
while (right < 2 * N - 1):
    right += 1
    if (belt[right] in sushi):
        sushi[belt[right]] += 1
    else:
        sushi[belt[right]] = 1
    if (len(sushi) >= ans):
        if (c in sushi):
            ans = len(sushi)
        else:
            ans = len(sushi) + 1
    sushi[belt[left]] -= 1
    if (not sushi[belt[left]]):
        del sushi[belt[left]]
    left += 1

print(ans)


