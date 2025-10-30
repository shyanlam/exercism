def is_triangle(a: int|float, b: int|float, c: int|float) -> bool:
    return (a != 0 and b != 0 and c != 0 and
            a + b >= c and b + c >= a and c + a >= b)


def equilateral(sides: tuple[int|float, int|float, int|float]) -> bool:
    a, b, c = sides
    return is_triangle(a, b, c) and a == b == c


def isosceles(sides: tuple[int|float, int|float, int|float]) -> bool:
    a, b, c = sides
    return is_triangle(a, b, c) and (a == b or b == c or a == c)


def scalene(sides: tuple[int|float, int|float, int|float]) -> bool:
    a, b, c = sides
    return is_triangle(a, b, c) and (a != b != c != a)
