import sys

def alpha_to_num(x): # 알파뱃을 숫자로 변환
    if (ord(x) >= 65 and ord(x) <= 90):
        return (ord(x) - 64)
    else:
        return (0)

def preorder_traversal(index):
    print(chr(64 + index), end = '')
    if (tree[index][1]):
        preorder_traversal(tree[index][1])
    if (tree[index][2]):
        preorder_traversal(tree[index][2])

def inorder_traversal(index):
    if (tree[index][1]):
        inorder_traversal(tree[index][1])
    print(chr(64 + index), end='')
    if (tree[index][2]):
        inorder_traversal(tree[index][2])

def postorder_traversal(index):
    if (tree[index][1]):
        postorder_traversal(tree[index][1])
    if (tree[index][2]):
        postorder_traversal(tree[index][2])
    print(chr(64 + index), end='')

N = int(input())
tree = [[0 for _ in range(3)] for _ in range(N + 1)]
for i in range(N): #make tree
    a,b,c = sys.stdin.readline().split()
    tree[alpha_to_num(b)][0] = alpha_to_num(a)
    tree[alpha_to_num(c)][0] = alpha_to_num(a)
    tree[alpha_to_num(a)][1] = alpha_to_num(b)
    tree[alpha_to_num(a)][2] = alpha_to_num(c)

preorder_traversal(1)
print()
inorder_traversal(1)
print()
postorder_traversal(1)