from logging import exception
import math
from unittest import result


class Even:
    def __init__(self, max, prime=2) -> None:
        self.n = 0
        self.max = max
        self.prime = prime

    def __next__(self):
        if self.n <= self.max:
            result = self.n
            self.n += 2
            return result
        else:
            raise StopIteration

    def next_prime(self):
        if self.n <= self.max:
            _prime = self.prime
            # for next_prime in [x for x in range(_prime + 1, self.max)]:
            #     is_prime = True
            next_prime = self.prime + 1
            is_prime = True
            # next_prime += 1
            list = [x for x in range(2, int(math.sqrt(next_prime) + 1))]
            for j in list:
                if next_prime % j == 0:
                    is_prime = False
                if j == int(math.sqrt(next_prime)) and is_prime == False:
                    j = 2
                    next_prime += 1
                    list = [x for x in range(
                        2, int(math.sqrt(next_prime) + 1))]
            if is_prime == True:
                self.prime = next_prime
            return _prime


numbers = Even(10)
# print(numbers.__next__())
# print(numbers.__next__())
# print(numbers.__next__())
print(numbers.next_prime())
print(numbers.next_prime())
print(numbers.next_prime())
print(numbers.next_prime())
print(numbers.next_prime())
print(numbers.next_prime())

# print([x for x in range(10)])
# is_prime = True
# for p in range(math.sqrt(i) + 1):
# 	if i % p == 0:
# 		is_prime = False
# 		break
# if is_prime == True:
# 	self.prime = p
# 	break
