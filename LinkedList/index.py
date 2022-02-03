

# Node class
class Node:
    def __init__(self, data) -> None:
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self) -> None:
        self.head = None
        self.tail = None
        self.len = 0

    def printList(self):
        temp = self.head
        while(temp):
            print(temp.data)
            temp = temp.next

    def unshift(self, data):
        newNode = Node(data)
        newNode.next = self.head
        self.head = newNode
        return self

    def shift(self, data):
        newNode = Node(data)
        newNode.next = self.head
        self.head = newNode
        return self

    def push(self, data):
        newNode = Node(data)
        if self.head is None:
            self.head = newNode
            return self
        lastNode = self.head
        while (lastNode.next):
            lastNode = lastNode.next
        lastNode.next = newNode
        return self

    def pop(self):
        if self.head is None:
            return self
        lastNode = self.head
        secondLastNode = self.head
        while lastNode.next:
            secondLastNode = lastNode
            lastNode = lastNode.next
        secondLastNode.next = None
        return self

    def delNode(self, data):
        temp = self.head
        if (temp != None and temp.data == data):
            self.head = temp.next
            temp.next = None
            return self
        while (temp is not None):
            if temp.data == data:
                break
            prev = temp
            temp = temp.next
        if temp == None:
            return self
        prev.next = temp.next
        temp = None
        return self


if __name__ == '__main__':
    llist = LinkedList()
    llist.push(4).push(5).push(6)
    llist.unshift(3).unshift(2).printList()
    print('\n')
    llist.delNode(6).printList()
