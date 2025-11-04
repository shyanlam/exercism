def sum_of_multiples(limit: int, multiples: list[int]) -> int:
    return sum(set([point
                    for base in multiples
                    if base
                    for point in range(base, limit, base)]))

