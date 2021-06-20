from collections import deque

def solution(prices):
    answer = [0 for _ in range(len(prices))]
    s = deque()
    for i in range(len(prices)):
        if (not len(s)):
            s.appendleft((i, prices[i]))
        else:
            while(len(s)):
                ind, val = s.popleft()
                if (val <= prices[i]):
                    s.appendleft((ind, val))
                    break
                answer[ind] = i - ind
            s.appendleft((i, prices[i]))
    while (len(s)):
        ind, val = s.popleft()
        answer[ind] = len(prices) - 1 - ind            
    return answer
