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
    return max(HeightOfTree(node.left), HeightOfTree(node.right)) + 1


root = Node(1)
root.left = Node(2)
root.left.left = Node(4)
root.left.right = Node(5)
root.right = Node(3)
root.right.left = Node(6)
root.right.right = Node(7)
root.right.right.right = Node(10)
root.right.right.right.left = Node(102)
print('Hieght of tree is %d' % (HeightOfTree(root)))


print2DTree(root)

# q = [0]
# print(q.insert(len(q), 4))
# print(q.insert(len(q), 5))
# print(q.pop(0))
