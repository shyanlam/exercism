import math

def score(x: float, y:float) -> int:
    radius: float = math.sqrt(x**2 + y**2)
    return (radius <= 1) * 10 or (radius <= 5) * 5 or (radius <= 10) * 1 or 0

