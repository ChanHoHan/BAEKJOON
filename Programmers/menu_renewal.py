total = [[] for _ in range(11)]
max_val = [0 for _ in range(11)]
valid = dict()

def comb(ind, depth, max_depth, dish, val):
    global total, valid
    
    if (depth == max_depth):
        if (val not in valid):
            valid[val] = 1
        elif (valid[val]):
            if (valid[val] == 1):
                total[depth].append(val)
            valid[val] += 1
            if (max_val[depth] < valid[val]):
                max_val[depth] = valid[val]
        return
    for i in range(ind, len(dish)):
        comb(i + 1, depth + 1, max_depth, dish, val + dish[i])
    
def solution(orders, course):
    global total
    
    new_order = []
    for dish in orders:
        tmp = ""
        dish_li = sorted(dish)
        for i in dish_li:
            tmp += i
        new_order.append(tmp)
    answer = []
    
    for dish in new_order:
        for j in range(1, len(dish) + 1):
            comb(0, 0, j, dish, "")
    for i in course:
        for val in total[i]:
            if (valid[val] == max_val[i]):
                answer.append(val)
    answer.sort()
    return answer
