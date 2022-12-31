from queue import Queue

q = Queue(maxsize=5)

# print(q.qsize())
# q.put('a')
# q.put('b')
# q.put('c')
# print('isfull ', q.full())

# Insert elements 1 to 5 in the queue
for i in range(0, 5):
    q.put(i)
print('get -> ', q.queue[0])
print('get -> ', q.queue[1])
for i in range(0, 5):
    # pass
    print('Now, = ', q.queue[i])
print(q.qsize())
print(q.get())
print(q.qsize())
# Now, the queue looks like this:
# (First) 1 <- 2 <- 3 <- 4 <- 5
# for i in range(q.qsize()):
#     y = q.get()
#     print(y)
#     q.put(y)
print(q.qsize())
# items = [3, 4, 5]
# print(items.insert(0, 3))
# print(items)
# print(items.pop(0))
