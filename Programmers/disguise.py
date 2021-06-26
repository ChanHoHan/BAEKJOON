def solution(clothes):
    c_dict = dict()
    for i in clothes:
        if i[1] in c_dict:
            c_dict[i[1]] += 1
        else:
            c_dict[i[1]] = 1
    li = []
    for _, val in c_dict.items():
        li.append(val)
    val = 1
    for i in li:
        val *= (i + 1)    
    return val - 1
