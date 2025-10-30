import math

def score(x: float, y:float) -> int:
    radius: float = math.sqrt(x**2 + y**2)
    match radius:
        case r if 5 < r <= 10: return 1
        case r if 1 < r <= 5: return 5
        case r if r <= 1: return 10
        case _: return 0

