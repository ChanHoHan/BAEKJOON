def solution(people, limit):
    answer = 0
    people.sort()
    left = 0
    right = len(people) - 1
    while (left < right):
        val = people[left] + people[right]
        if (val > limit):
            right-=1
        else:
            left += 1
            right -= 1
        answer += 1
    if (left == right):
        answer += 1
    return answer
