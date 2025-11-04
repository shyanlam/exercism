def sum_of_multiples(limit: int, multiples: list[int]) -> int:
    points: set[int] = set()
    for base in multiples:
        if base != 0:
            for n in range(base, limit, base):
                points.add(n)
    return sum(points)

