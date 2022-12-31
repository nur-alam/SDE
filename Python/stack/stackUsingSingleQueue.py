q = []


def push(val):
    size = len(q)
    q.append(val)
    for i in range(size):
        q.append(q.pop(0))


def pop():
    if (len(q) == 0):
        print('No elements')
        return -1
    return q.pop(0)


def peek():
    if(len(q) == 0):
        return -1
    return q[-1]


def isEmpty():
    return len(q) == []


if __name__ == '__main__':
    # s = []
    q.push(10)
    q.push(20)
    q.peek('Top element : ' + q.peek())
