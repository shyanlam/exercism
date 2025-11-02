def flatten(iterable) -> list:
    result = list()
    for item in iterable:
        if item is None:
            continue
        if hasattr(item, "__iter__"):
            result += flatten(item)
        else:
            result.append(item)
    return result
