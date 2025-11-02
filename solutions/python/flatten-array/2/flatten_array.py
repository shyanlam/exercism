def flatten(iterable) -> list:
    result = list()
    for item in iterable:
        if hasattr(item, "__iter__"):
            result += flatten(item)
        elif item is not None:
            result.append(item)
    return result
