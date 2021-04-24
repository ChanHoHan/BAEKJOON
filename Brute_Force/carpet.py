def solution(brown, yellow):
    answer = []
    w_max = brown // 2 - 1
    for i in range(1, w_max + 1):
        col = i + 2
        row = w_max - i + 1
        if ((col - 2) * (row - 2) == yellow):
            answer.append(row)
            answer.append(col)
            return answer
    return answer