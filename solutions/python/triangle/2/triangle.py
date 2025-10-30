def valid_triangle(func):
    def inner(sides: tuple[float, float, float]) -> bool:
        return (sum(sides) > max(sides) * 2) and func(sides)
    return inner



@valid_triangle
def equilateral(sides: tuple[float, float, float]) -> bool:
    return len(set(sides)) == 1


@valid_triangle
def isosceles(sides: tuple[float, float, float]) -> bool:
    return len(set(sides)) < 3


@valid_triangle
def scalene(sides: tuple[float, float, float]) -> bool:
    return len(set(sides)) == 3
