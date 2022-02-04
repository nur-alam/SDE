# arr = [1, 2, 3, 4, 5, 6, 0, 0, 0, 0, 0]
# # 2, 10
# num = 10
# pos = 2
# arrSize = 6
# # arr[6] = 23
# # print(arr)
# # 5, 4, 3, 2,
# for i in range(5, 1, -1):
#     arr[i+1] = arr[i]
# print(i)
# arr[i] = num
# print(arr)
# arr[2] = 9
# arr.append(4)
# arr.pop(0)
# arr.insert(0, 10)
# print(arr)

# [1, next] [2, next] [3, next] [4, None]

class Node:
    def __init__(self, data=None, next=None) -> None:
        self.data = data
        self.next = next


n = Node(10)
n2 = Node(20)
n.next = n2
n3 = Node(30)
n2.next = n3
# print(n.data)
# print(n2.data)
# print(n.next.data)
print(n.next.next.data)


# 23434 3245 345234 234532 2345324 1354345

# # Represent a node of doubly linked list
# class Node:
#     def __init__(self, data):
#         self.data = data
#         self.prev = None
#         self.next = None

# class SortList:
#     def __init__(self):
#         self.head = None
#         self.tail = None

#     def addNode(self, data):
#         newNode = Node(data)

#         if(self.head == None):
#             self.head = self.tail = newNode
#             self.head.prev = None
#             self.tail.next = None
#         else:
#             self.tail.next = newNode
#             newNode.prev = self.tail
#             self.tail = newNode
#             self.tail.next = None

#     def sortList(self):
#         if(self.head == None):
#             return
#         else:
#             current = self.head
#             while(current.next != None):
#                 index = current.next
#                 while(index != None):
#                     if(current.data > index.data):
#                         temp = current.data
#                         current.data = index.data
#                         index.data = temp
#                     index = index.next
#                 current = current.next

#     def display(self):
#         current = self.head
#         if(self.head == None):
#             print("List is empty")
#             return
#         while(current != None):
#             print(current.data),
#             current = current.next

#         print()

# doubelyLinkedList = SortList()
# # Add nodes to the list
# doubelyLinkedList.addNode(1/2)
# doubelyLinkedList.addNode(2/3)
# doubelyLinkedList.addNode(4/7)
# # dList.addNode(5)
# # dList.addNode(2)
# # Sorting list
# doubelyLinkedList.sortList()

# # Displaying original list
# print("Original list: ")
# dList.display()

# # Sorting list
# dList.sortList()

# # Displaying a sorted list

# print("Sorted list: ")
# dList.display()
