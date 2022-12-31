

class Deque:
    def __init__(self) -> None:
        self.items = []

    def isEmpty(self):
        return self.items == []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def unshift(self, item):
        self.items.insert(0, item)

    def shift(self):
        return self.items.pop(0)

    def size(self):
        return len(self.items)


d = Deque()
print(d.isEmpty())
d.push(8)
d.push(5)
d.unshift(7)
d.unshift(10)
print(d.size())
print(d.isEmpty())
d.push(11)
print(d.pop())
print(d.shift())
d.unshift(55)
d.push(45)
print(d.items)
