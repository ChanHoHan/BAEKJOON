import sys

A, B = sys.stdin.readline().split()

def same_check(val):
    A_len = len(A)
    rtn = 0
    for i in range(A_len):
        if (A[i] != B[i + val]):
            rtn+=1
    return (rtn)

def find_min_difference():
    rtn = 51
    AB_range = len(B) - len(A) + 1
    for i in range(AB_range):
        rtn = min(rtn, same_check(i))
    return (rtn)

print(find_min_difference())