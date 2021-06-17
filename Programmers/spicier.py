import heapq

def solution(scoville, K):
    answer = 0
    heap = []
    for i in scoville:
        heapq.heappush(heap, i)
    while True:
        val1 = heapq.heappop(heap)
        if (val1 >= K):
            heapq.heappush(heap, val1)
            break
        if (not len(heap)):
            answer = -1
            break
        val2 = heapq.heappop(heap)
        heapq.heappush(heap, (val1 + 2 * val2))
        answer+=1
    return answer
