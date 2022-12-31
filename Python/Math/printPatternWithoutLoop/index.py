# Input: n = 16
# Output: 16, 11, 6, 1, -4, 1, 6, 11, 16

# Input: n = 10
# Output: 10, 5, 0, 5, 10

# with loop
# def printPattern(n):
#     print(n)
#     m = n - 5
#     flag = False
#     while True:
#         print(m)
#         if m == n:
#             break
#         elif m > 0 and flag == False:
#             m -= 5
#         else:
#             m += 5
#             flag = True

# with recursion
import sys
sys.setrecursionlimit(10**6)


class printPattern:
    # def __init__(self) -> None:
    #     self.list = []

    def pattern(n):
        # Base case (When n becomes 0 or negative)
        list = []

        def recursion(n):
            if n <= 0:
                list.append(n)
                return
            list.append(n)
            recursion(n - 5)
            list.append(n)
        recursion(n)
        return list


ob = printPattern()
list = printPattern.pattern(16)
print('list ', list)
# for i in list:
#     print(i, end=' ')


# visualization

# 16, 11, 6, 1, -4, 1, 6, 11, 16
# print(16, end=", ") d
# printPattern(16 - 5) (11)
# print(16, end=", ")
#     print(11, end=", ") d
#     printPattern(11 - 5)(6)
#     print(11, end=", ")
#         print(6, end=", ") d
#         printPattern(6 - 5)(1)
#         print(6, end=", ")
#             print(1, end=", ") d
#             printPattern(1 - 5)(-4)
#             print(1, end=", ")
