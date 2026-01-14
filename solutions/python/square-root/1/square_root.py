
def square_root(number: int) -> int:
    prev1 = -1
    x0 = 1
    while True:
        x1 = (x0 + number // x0) // 2
        if x1 == x0:
            return x1

        if x1 == prev1:
            return min(x1, prev1)

        prev1, x0 = x0, x1
