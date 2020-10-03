import sys

T = int(input())
answer = []

for _ in range(T):
    N = int(input())

    applicant = []

    for _ in range(N):
        applicant.append(list(map(int,sys.stdin.readline().split())))

    applicant = sorted(applicant, key= lambda x:x[0])

    val = applicant[0][1]
    cnt = 1
    for i in range(1,len(applicant)):
        if val > applicant[i][1]:
            val = applicant[i][1]
            cnt+=1

    answer.append(cnt)

for i in answer:
    print(i)
