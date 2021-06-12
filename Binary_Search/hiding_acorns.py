#15732
import sys

N, K, D = map(int, sys.stdin.readline().split())
li = [list(map(int, sys.stdin.readline().split())) for _ in range(K)]

left = 1
right = 1000000

while (left <= right):
    mid = (left + right) // 2
    cnt = 0
    for i in range(K):
        start, end, interval = li[i]
        if (mid < start):
            continue
        elif (start <= mid and mid <= end):
            cnt += (mid - start) // interval + 1
        else:
            cnt += (end - start) // interval + 1
    if (cnt >= D):
        right = mid - 1
    else:
        left = mid + 1
print(left)
