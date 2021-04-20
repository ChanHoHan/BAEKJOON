def solution(citations):
    citations.sort()
    answer = 0
    c_len = len(citations)
    for i in range(len(citations)):
        if c_len >= citations[i]:
            answer = citations[i]
        elif answer < c_len:
            answer = c_len
        c_len -= 1
    return answer
