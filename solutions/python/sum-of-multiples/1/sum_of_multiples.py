def sum_of_multiples(limit: int, multiples: list[int]) -> int:
    points: set[int] = set()
    for base in multiples:
        for n in range(limit):
            if n * base < limit:
                points.add(n * base)
    return sum(points)

