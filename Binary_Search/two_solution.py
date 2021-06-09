#2470
import sys

N = int(sys.stdin.readline())
li = list(map(int, sys.stdin.readline().split()))
left = 0
right = N - 1
min_ = 3000000000
ans = [0, 0]
li.sort()
while (left < right):
    val = li[right] + li[left]
    if (abs(val) < min_):
        min_ = abs(val)
        ans[0] = li[left]
        ans[1] = li[right]
    if (val < 0):
        left += 1
    else:
        right -= 1
ans.sort()
print(ans[0], ans[1])
