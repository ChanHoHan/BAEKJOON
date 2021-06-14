#10487
import sys

m = int(sys.stdin.readline())
op = ['+', '-', '*', '//']
ans = ""

def cal(n, depth, val):
    global ans

    if (depth == 3):
        if (n == eval(val)):
            ans = val
            return (1)
        return (0)
    if(cal(n, depth + 1, val + op[0] + '4') or cal(n, depth + 1, val + op[1] + '4') or
    cal(n, depth + 1, val + op[2] + '4') or cal(n, depth + 1, val + op[3] + '4')):
        return (1)
    return (0)

for _ in range(m):
    n = int(sys.stdin.readline())
    if (cal(n, 0, '4')):
        i = 0
        while (i < len(ans)):
            print(ans[i], end=" ")
            if (ans[i] == '/'):
                i += 1
            i+=1
        print("=", n)
    else:
        print("no solution")
