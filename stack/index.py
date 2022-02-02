from collections import deque
from queue import LifoQueue

#  put(), get(), empty(), qsize(), full(), maxsize()
stack = LifoQueue(maxsize=5)
stack.put(1)
stack.put(2)
stack.put(3)
stack.put(4)
for i in range(0, stack.qsize()):
    print(stack.get(), end=' ')
print('\nis full ', stack.full())
print('stack size ', stack.qsize())
# print(stack.get())
# print(stack[0])


# stack implementation using collection.deque

# stack = deque()
# stack.append(4)
# stack.append(5)
# stack.append(6)
# stack.append(7)
# print(stack)
# print(stack.pop())
# print(stack)
# print(len(stack))
# print(stack[-1])

class Stack:
    def __init__(self) -> None:
        self.items = []

    def isEmpty(self):
        return self.items == []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def peek(self):
        return self.items[len(self.items) - 1]

    def size(self):
        return len(self.items)


# s = Stack()
# print(s.isEmpty())
# s.push(4)
# s.push('dog')
# print(s.peek())
# s.push(True)
# print(s.size())
# print(s.isEmpty())
# s.push(8.4)
# print(s.items)
# print(s.pop())
# print(s.pop())
# print(s.size())

# stack using list
# stack = []
# stack.append(4)
# stack.append(5)
# stack.append(6)
# print(stack)
# stack.pop()
# print(stack)
# print(stack[0])
# print(stack[-1])
