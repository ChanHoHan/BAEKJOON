import sys

cnt = 0
def recursion(val):
    global cnt
    if (len(val) < 2):
        if (not (int(val) % 3)):
            return (1)
        else:
            return (0)
    cnt += 1
    t = 0
    for i in val:
        t += int(i)
    return (recursion(str(t)))

X = sys.stdin.readline().strip()
ans = recursion(X)
print(cnt)
if (ans):
    print("YES")
else:
    print("NO")