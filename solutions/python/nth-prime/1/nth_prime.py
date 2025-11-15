import itertools
import math


def is_prime(number: int) -> bool:
    for n in range(2, int(math.sqrt(number)) + 1):
        if number % n == 0:
            return False
    return True


def prime(nth: int) -> int:
    if nth == 0:
        raise ValueError('there is no zeroth prime')
    if nth < 0:
        raise ValueError('nth cannot be negative')

    prime_count = 0
    number = 2
    while True:
        if is_prime(number):
            prime_count += 1
            if prime_count == nth:
                break
        number += 1
    return number
