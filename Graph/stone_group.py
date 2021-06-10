#12886
import sys
import copy
from collections import deque
from itertools import permutations

A, B, C = map(int, sys.stdin.readline().split())
visited = set()
q = deque()

def check_next(li):
    s = []
    if (li[0] != li[1]):
        if (li[0] > li[1]):
            s.append((1, 0))
        else:
            s.append((0, 1))
    if (li[1] != li[2]):
        if (li[1] > li[2]):
            s.append((2, 1))
        else:
            s.append((1, 2))
    if (li[2] != li[0]):
        if (li[2] > li[0]):
            s.append((0, 2))
        else:
            s.append((2, 0))
    return (s)

def check_same(li):
    if (li[0] == li[1] == li[2]):
        return (1)
    return (0)

visited.add((A, B, C))
q.append([A, B, C])
if (check_same([A, B, C])):
    print(1)
    exit(0)
while q:
    li = q.popleft()
    next_list = check_next(li)
    for i in range(len(next_list)):
        tmp = copy.deepcopy(li)
        small_index, big_index = next_list[i]
        tmp[big_index] = tmp[big_index] - tmp[small_index]
        tmp[small_index] += tmp[small_index]
        fl = 0
        for a,b,c in list(permutations(tmp, 3)):
            if (a,b,c) in visited:
                fl = 1
                break
        else:
            visited.add((tmp[0], tmp[1], tmp[2]))
        if (fl):
            continue
        if (check_same(tmp)):
            print(1)
            exit(0)
        q.append(tmp)
print(0)

