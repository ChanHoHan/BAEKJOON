import sys

N, K = map(int, sys.stdin.readline().split())
li = []
for _ in range(N):
    a = int(sys.stdin.readline())
    li.append(a)
li.sort()
left = 1
right = 1000000000
while (left <= right):
    mid = (left + right) // 2
    _K = K
    for num in li:
        if (num < mid):
            if (mid - num <= _K):
                _K -= (mid - num)
            else:
                right = mid - 1
                break
    else:
        left = mid + 1

print(right)