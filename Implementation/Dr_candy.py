#2508
import sys

t = int(sys.stdin.readline())
for _ in range(t):
    nothing = sys.stdin.readline()
    r, c = map(int, sys.stdin.readline().split())
    ans = 0
    li = ['x' * (c + 2)]
    li += ['x' + sys.stdin.readline().strip() + 'x' for _ in range(r)]
    li += ['x' * (c + 2)]
    for i in range(1, r + 1):
        for j in range(1, c + 1):
            if (li[i][j] == 'o' and li[i - 1][j] == 'v' and li[i + 1][j] == '^'):
                ans+=1
            elif (li[i][j] == 'o' and li[i][j - 1] == '>' and li[i][j + 1] == '<'):
                ans+=1
    print(ans)
