def primes(limit: int) -> list[int]:
    result: list[int] = []
    multiples = set()
    for num in range(2, limit + 1):
        if num not in multiples:
            result.append(num)
            multiples.update(range(num*2, limit + 1, num))

    return result

