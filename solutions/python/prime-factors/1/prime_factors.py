import math

def is_prime(value : int) -> bool:
    for n in range(2, int(math.sqrt(value))):
        if value % n == 0:
            return False
    return True

def factors(value: int) -> list[int]:
    result: int[int] = []
    n = 2
    while value != 1:
        if is_prime(n):
            while value % n == 0:
                result.append(n)
                value = value // n
        n += 1

    return result