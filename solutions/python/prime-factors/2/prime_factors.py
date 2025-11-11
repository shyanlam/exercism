import math

def factors(value: int) -> list[int]:
    result: int[int] = []
    n = 2
    while value != 1:
        if value % n == 0:
            result.append(n)
            value //= n
        else:
            n += 1

    return result