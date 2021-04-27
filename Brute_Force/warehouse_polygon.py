import sys

N = int(sys.stdin.readline())
li = []
h_max = 0
ans = 0
find_max = []
for i in range(N):
    li.append(list(map(int, sys.stdin.readline().split())))
    find_max.append(li[i][1])
find_max.sort()
h_max = find_max[-1]

li.sort()
new_li = [0 for _ in range(li[-1][0] + 1)]
for i in range(N):
    new_li[li[i][0]] = li[i][1]

left = 0
right = 0
fl = 0
for i in range(len(new_li)):
    if new_li[i] == h_max:
        if (not fl):
            left = i
            right = i
            fl = 1
        else:
            right = i
ans += h_max * (right - left + 1)

prev_height = 0
for i in range(len(new_li)): #up
    if prev_height < new_li[i]:
        prev_height = new_li[i]
    if (h_max == prev_height):
        break
    ans+=prev_height

prev_height = 0
for i in range(len(new_li) - 1, -1, -1):
    if prev_height < new_li[i]:
        prev_height = new_li[i]
    if (h_max == prev_height):
        break
    ans+=prev_height
print(ans)

