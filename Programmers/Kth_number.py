def solution(array, commands):
    answer = []
    for i in commands:
        a, b, k = i
        li = array[a - 1: b]
        answer.append(sorted(li)[k - 1])
    return answer
