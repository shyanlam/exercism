def flatten(iterable: list) -> list:
    for i, _ in enumerate(iterable):
        while i < len(iterable) and isinstance(iterable[i], list):
            iterable[i:i + 1] = iterable[i]
    return [x for x in iterable if x is not None]
