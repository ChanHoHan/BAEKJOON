import sys

N = int(input())
alpha = dict()

def alpha_increasing(word):
    word_len = len(word)-1
    for i in range(len(word)):
        val = pow(10, word_len)
        if word[i] not in alpha:
            alpha[word[i]] = val
        else:
            alpha[word[i]] += val
        word_len -=1

word = []
for _ in range(N): # adding words
    word.append(sys.stdin.readline().strip())

for i in word:
    alpha_increasing(i)

li = []
for key in alpha.keys(): # making list for sorting
    li.append([key,alpha[key]])
li = sorted(li, key=lambda x: x[1], reverse=True)

val = 9
for i in range(len(li)): # changing alphabet to the number
    alpha[li[i][0]] = val
    val -=1

new_word = []
for i in range(len(word)):
    tmp = list(word[i])
    for j in range(len(tmp)):
        tmp[j] = str(alpha[tmp[j]])
    new_word.append(''.join(tmp))

word = list(map(int, new_word))
print(sum(word))
