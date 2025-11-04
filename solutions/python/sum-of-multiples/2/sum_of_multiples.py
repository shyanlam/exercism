def sum_of_multiples(limit: int, multiples: list[int]) -> int:
    return sum(set([n * base
                    for base in multiples
                    for n in range(limit)
                    if n * base < limit]))

