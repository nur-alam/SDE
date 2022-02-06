

# Node class
class Node:
    def __init__(self, data) -> None:
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self) -> None:
        self.head = None
        self.len = 0

    def printList(self):
        temp = self.head
        while(temp):
            print(temp.data)
            temp = temp.next

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

    # function to find out middle element
    def middle(self, start, last):
        if start == None:
            return None
        slow = start
        fast = start.next
        while fast != last:
            fast = fast.next
            if fast != last:
                slow = slow.next
                fast = fast.next
        return slow

    # Function for implementing the Binary
    # Search on linked list
    def binarySearch(self, value):
        start = self.head
        last = None
        while True:
            mid = self.middle(start, last)
            if mid == None:
                return None
            if (mid.data == value):
                return mid
            elif (mid.data < value):
                start = mid.next
            else:
                last = mid
            if (last == start):
                break
        return None


if __name__ == '__main__':
    llist = LinkedList()
    # llist.push(4).push(5).push(6).push(7).push(8)
    # llist.push(4)
    # llist.push(4).push(5)
    # llist.push(4).push(5).push(6)
    print('')
    isPresent = llist.binarySearch(5)
    if isPresent != None:
        print('head ', isPresent.data)
    else:
        print('not present')
