class Node:
    def __init__(self, data) -> None:
        self.left = None
        self.right = None
        self.val = data


def inorder(root):
    if (not root):
        return None
    inorder(root.left)
    print(str(root.val) + " -> ", end='')
    inorder(root.right)


def postorder(root):
    if root:
        postorder(root.left)
        postorder(root.right)
        print(str(root.val) + ' -> ', end='')


def preorder(root):
    if root:
        print(str(root.val) + ' -> ', end='')
        preorder(root.left)
        preorder(root.right)


def print2DTree(root, space=0, LEVEL_SPACE=5):
    if (root == None):
        return
    space += LEVEL_SPACE
    print2DTree(root.right, space)
    # print() # neighbor space
    for i in range(LEVEL_SPACE, space):
        print(end=" ")
    print("|" + str(root.val) + "|")
    print2DTree(root.left, space)


root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.right.left = Node(6)
root.right.right = Node(7)
root.right.right.right = Node(55)

print('Inorder traversal ')
inorder(root)
print('Postorder traversal ')
postorder(root)
print('Preorder')
preorder(root)
# print2DTree(root)
#                     1
#             2                 3
#     4              5      6       7
#                                      55
