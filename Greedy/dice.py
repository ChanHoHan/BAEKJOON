#1041
def one(dice):
    return (sorted(dice)[1])

def two(dice):
    min_val = 999999

    li = [(1,2), (1,3), (1,4), (1,5), (2,3), (2,4), (2,6), (3,5), (3,6), (4,5), (4,6), (5,6)]
    for item in li:
        val = dice[item[0]] + dice[item[1]]
        if (min_val > val):
            min_val = val
    return (min_val)

def three(dice):
    min_val = 999999

    li = [(1,2,3), (1,2,4), (1,3,5), (1,4,5), (2,3,6), (2,4,6), (3,5,6), (4,5,6)]
    for item in li:
        val = dice[item[0]] + dice[item[1]] + dice[item[2]]
        if (min_val > val):
            min_val = val
    return (min_val)

N = int(input())
dice = list(map(int, input().split()))
dice.insert(0, 0)
if (N == 1):
    dice.sort()
    print(sum(dice) - dice[-1])
elif (N == 2):
    val = two(dice) * 4 + three(dice) * 4
    print(val)
else:
    val = one(dice) * (4 * (N - 1) * (N - 2) + (N - 2) * (N - 2)) + two(dice) * (4 * (N - 1) + 4 * (N - 2)) + three(dice) * 4
    print(val)
