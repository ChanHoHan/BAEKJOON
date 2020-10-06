import sys

N = int(input())
li = list(enumerate(list(map(int,sys.stdin.readline().split()))))
answer = [0 for _ in range(N)]
for i in range(len(li)):
    ind, height = li[i]
    cnt = 0
    indx = 0
    for j in range(len(answer)):
        if cnt == height and answer[j] == 0:
            break
        if answer[j] == 0:
            cnt +=1
        indx+= 1
    answer[indx] = ind+1

for i in answer:
    print(i, end=' ')
