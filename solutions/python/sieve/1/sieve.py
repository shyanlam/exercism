def primes(limit: int) -> list[int]:
    result: list[int] = []
    bit_list: list[bool] = [True for n in range(limit + 1)]
    for n in range(2, limit + 1):
        if bit_list[n]:
            result.append(n)
            for n2 in range(n+n, limit+1, n):
                bit_list[n2] = False
    return result

