def append(list1: list, list2: list) -> list:
    return list1 + list2


def concat(lists: list[list]):
    result: list = []
    for items in lists:
        result[len(result):] = items
    return result


def filter(function, lst: list) -> list:
    result: list = []
    for item in lst:
        if function(item):
            result += [item]
    return result


def length(lst: list) -> int:
    count: int = 0
    for item in lst:
        count += 1
    return count


def map(function, lst: list) -> list:
    result: list = []
    for item in lst:
        result += [function(item)]
    return result


def foldl(function, lst: list, initial: float) -> float:
    result = initial
    for item in lst:
        result = function(result, item)
    return result


def foldr(function, lst: list, initial: float) -> float:
    return foldl(function, reverse(lst), initial)


def reverse(lst: list) -> list:
    result: list = []
    for item in lst:
        result = [item] + result
    return result
