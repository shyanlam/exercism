def rows(letter: str) -> list[str]:
    ALPHAS: str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    index = ALPHAS.index(letter)
    base_value = ALPHAS[index: 0: -1] + ALPHAS[0: index + 1]
    result: list[str] = list()
    for n in range(index + 1):
        line = "".join(map(lambda c: c if c == ALPHAS[n] else " ", base_value))
        result.insert(n, line)
        if n < index:
            result.insert(-n, line)
    return result

