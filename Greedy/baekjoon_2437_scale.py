import sys

N = int(input())
li = list(map(int,sys.stdin.readline().split()))
li.sort()


if len(li) == 1:
    if li[0] > 1:
        print(1)
    else:
        print(2)
else:
    check = [li[0]]
    if check[0] >1:
        print(1)
    else:
        ind = 1
        while True:
            if ind > len(li)-1:
                print(check[-1]+1)
                break
            val = li[ind]
            if check[-1]+1 < val:
                print(check[-1]+1)
                break
            elif check[-1]+1 == val:
                check.append(sum(li[:ind+1]))
            else:
                check[-1] += val
            ind+=1
