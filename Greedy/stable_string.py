#4889
import sys
from collections import deque

a = '-'
T = 1

def inp():
    global a
    a = sys.stdin.readline().strip()
    if (a[0] == '-'):
        return (0)
    return (1)

while inp():
    s = deque()
    ans = 0
    tmp = 's'
    for i in range(len(a)):
        if (a[i] == ' '):
            continue
        if (a[i] == '}'):
            if (len(s) > 0):
                t = s.pop()
                if (t == '{'):
                    continue
                s.append(t)
                s.append(a[i])
            else:
                s.append(a[i])
        else:
            s.append(a[i])
    for i in range(len(s)):
        t = s.popleft()
        if (tmp == 's'):
            tmp = t
            continue
        if (tmp == '}' and t == '}'):
            ans+=1
        elif (tmp == '{' and t == '{'):
            ans+=1
        else:
            ans+=2
        tmp = 's'

    print(str(T)+".", end=" ")
    print(ans)
    T+=1
