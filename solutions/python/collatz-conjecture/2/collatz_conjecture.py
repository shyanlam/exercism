import itertools
def steps(number: int) -> int:
    if number <= 0:
        raise ValueError("Only positive integers are allowed")

    counter = itertools.count()
    while number != 1:
        number = number * 3 + 1 if number % 2 else number / 2
        next(counter)
    return next(counter)

