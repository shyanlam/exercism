def find(search_list: list[int], value: int) -> int:
    """ Return the index of the value within the list

    :param search_list: a list of sorted integers to be searched
    :param value: the value to search for
    :return: index of the value within the list
    """

    index = 0
    while search_list:
        mid = len(search_list) // 2
        if value < search_list[mid]:
            search_list = search_list[:mid]
        elif value > search_list[mid]:
            index += mid + 1
            search_list = search_list[mid + 1:]
        else:
            return index + mid

    raise ValueError("value not in array")
