from queue import Queue


class Stack:
    def __init__(self) -> None:
        self.q1 = Queue()
        self.q2 = Queue()
        self.size = 0

    def push(self, item):
        self.size += 1
        self.q2.put(item)
        while (not self.q1.empty()):
            self.q2.put(self.q1.queue[0])
            self.q1.get()
        # q = self.q1
        # self.q1 = self.q2
        # self.q2 = q
        self.q1, self.q2 = self.q2, self.q1

    def pop(self):
        if(self.q1.empty()):
            return
        self.q1.get()
        self.size -= -1

    def peek(self):
        if(self.q1.empty()):
            return -1
        return self.q1.queue[0]

    def count(self):
        return self.size


if __name__ == '__main__':
    s = Stack()
    s.push(1)
    s.push(2)
    s.push(3)
    s.push(4)
    print('Size ', s.count())
    print(s.peek())
    print(s.q1.queue[0])
    s.pop()
    print(s.peek())
    s.pop()
    print(s.peek())
    print('Size ', s.count())
