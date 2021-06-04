#19539
#2776
import sys
N = int(sys.stdin.readline().strip())
li = list(map(int,sys.stdin.readline().split()))

a = 0
b = 0
for i in range(len(li)):
    a += li[i] // 2
    b += li[i] % 2
if (a >= b and not((a - b) % 3)):
    print("YES")
else:
    print("NO")
