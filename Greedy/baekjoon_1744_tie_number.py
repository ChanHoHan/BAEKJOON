import sys

N = int(sys.stdin.readline())
li_positive = []
li_negative = []
zero = 0
for _ in range(N):
    tmp = int(sys.stdin.readline())
    if tmp > 0:
        li_positive.append(tmp)
    elif tmp == 0:
        zero = 1
    else:
        li_negative.append(tmp)

li_positive.sort(reverse= True) #positive sorting/ ex) 1 3 4 5 8
li_negative.sort() #negative sorting/ ex) -3 -2 -1

answer = 0
ind = 0
ans = 0
while True:
    if ind >= len(li_positive):
        break
    if ind == len(li_positive) -1:
        ans+= li_positive[ind]
        break
    if li_positive[ind+1] ==1:
        ans += li_positive[ind] + li_positive[ind + 1]
    else:
        ans += li_positive[ind]*li_positive[ind+1]
    ind+=2

ind = 0
neg = 0
while True:
    if ind >= len(li_negative):
        break
    if ind == len(li_negative) -1:
        if not zero:
            ans+=li_negative[ind]
        break
    ans += li_negative[ind]*li_negative[ind+1]
    ind+=2
print(ans)
