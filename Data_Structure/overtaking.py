//2002
import sys

N = int(input())
cars = []
biggeun = {}
youngsik = []
ans = 0
for i in range(N):
    a = sys.stdin.readline().rstrip()
    biggeun[a] = i
for _ in range(N):
    youngsik.append(sys.stdin.readline().rstrip())

for i in range(len(youngsik)):
    car_ind = biggeun[youngsik[i]]
    for j in range(i + 1 , len(youngsik)):
        back_car_ind = biggeun[youngsik[j]]
        if (car_ind > back_car_ind):
            ans+=1
            break
print(ans)
