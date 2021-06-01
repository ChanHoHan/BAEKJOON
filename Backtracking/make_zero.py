import copy
T = int(input())
op = "+- "
ans = []

def cal(li):
    ans = ""
    for i in range(len(li)):
        if li[i] == " ":
            continue
        ans+=li[i]
    return eval(ans)

def recursion(li, ind):
    if (len(li) <= ind):
        if (cal(li) == 0):
            ans.append(copy.deepcopy(li))
        return
    for i in range(3):
        li[ind] = op[i]
        recursion(li, ind + 2)
while(T):
    N = int(input())
    li = []
    ans = []
    for i in range(1, N+1):
        li.append(str(i))
        if i == N:
            break
        li.append(" ")
    recursion(li, 1)
    ans.sort()
    for i in range(len(ans)):
        for j in range(len(ans[i])):
            print(ans[i][j], end="")
        print()
    print()
    T-=1