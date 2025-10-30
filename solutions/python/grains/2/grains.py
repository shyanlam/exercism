def square(number: int) -> int:
    if number not in range(1, 65):
        raise ValueError('square must be between 1 and 64')
    return 2 ** (number - 1)


def total():
    # return sum(map(square, range(1, 65)))
    return 2 ** 64 - 1
