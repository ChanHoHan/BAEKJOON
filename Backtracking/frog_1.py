#15566
import sys

N, M = map(int, sys.stdin.readline().split())

frog_interestring = [list(map(int, sys.stdin.readline().split())) for _ in range(N)] # 개구리의 흥미도
flower_priority = [[] for _ in range(N+1)] # 연꽃 번호마다 개구리가 흥미있는 부분
for i in range(N):
    a, b = map(int, sys.stdin.readline().split())
    flower_priority[a].append(i)
    if (a != b):
        flower_priority[b].append(i)

log = [[] for _ in range(N + 1)] # 연꽃이 이동할 수 있는 부분
for i in range(M):
    a,b,t = map(int, sys.stdin.readline().split())
    log[a].append((b, t))
    log[b].append((a, t))

visited = [-1 for _ in range(N + 1)]
frog_position = [-1 for _ in range(N)]

def brute_force(ind): # 연꽃 기준
    if (ind == N + 1):
        return (True)
    get_frogs = flower_priority[ind]
    for frog in get_frogs:
        if (frog_position[frog] != -1):
            continue
        for x, t in log[ind]:
            if (visited[x] != -1 and frog_interestring[visited[x]][t - 1] != frog_interestring[frog][t - 1]):
                break
        else:
            visited[ind] = frog
            frog_position[frog] = ind
            if (brute_force(ind + 1)):
                return (1)
            visited[ind] = -1
            frog_position[frog] = -1
    return (0)


if (brute_force(1)):
    print("YES")
    for j in range(1, len(visited)):
        print(visited[j] + 1, end=" ")
else:
    print("NO")

