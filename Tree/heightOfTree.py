class Node:
    def __init__(self, item) -> None:
        self.left = None
        self.right = None
        self.val = item


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


def HeightOfTree(node):
    if node is None:
        return -1
    leftHeight = HeightOfTree(node.left)
    rightHeight = HeightOfTree(node.right)
    if leftHeight < rightHeight:
        return rightHeight + 1
    else:
        return leftHeight + 1


root = Node(1)
root.left = Node(2)
root.left.left = Node(4)
root.left.right = Node(5)
root.right = Node(3)
root.right.left = Node(6)
root.right.right = Node(7)
root.right.right.right = Node(10)
root.right.right.right.left = Node(102)
# print('Hieght of tree is %d' % (HeightOfTree(root)))

# root = Node(1)
# root.left = Node(2)
# root.right = Node(3)
# root.left.left = Node(4)
# root.left.right = Node(5)
# root.right.left = Node(6)
# root.right.right = Node(7)
# root.right.right.right = Node(55)


# print2DTree(root)
#                     1
#             2                 3
#     4              5      6       7
#                                      55

q = [0]
print(q.insert(len(q), 4))
print(q.insert(len(q), 5))
print(q.pop(0))
