def find(search_list: list[int], value: int) -> int:
    """ Return the index of the value within the list

    :param search_list: a list of sorted integers to be searched
    :param value: the value to search for
    :return: index of the value within the list
    """

    left: int = 0
    right: int = len(search_list) - 1
    while left <= right:
        index: int = (left + right) // 2
        if value == search_list[index]:
            return index
        if value < search_list[index]:
            right = index - 1
        else:
            left = index + 1

    raise ValueError("value not in array")

