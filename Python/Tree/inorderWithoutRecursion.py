class Node:
    def __init__(self, data, left=None, right=None) -> None:
        self.left = left
        self.right = right
        self.val = data


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

# Iterative function to inorder tree traversal


def inOrder(root):
    current = root
    stack = []
    while True:
        if current is not None:
            stack.append(current)
            current = current.left
        elif(stack):
            current = stack.pop()
            print(current.val, end=' ')
            current = current.right
        else:
            break
        # print()

# Driver program to test above function
# """ Constructed binary tree is
#             1
#           /   \
#          2     3
#        /  \
#       4    5   """
#     4 2 5 1 3
# root = Node(1, )
# root.left = Node(2)
# root.right = Node(3)
# root.left.left = Node(4)
# root.left.right = Node(5)


root = Node(1, right=Node(3), left=Node(2, left=Node(4), right=Node(5)))

inOrder(root)
