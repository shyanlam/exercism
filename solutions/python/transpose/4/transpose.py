import itertools
from itertools import zip_longest

def transpose(text: str) -> str:
    str_list = text.splitlines()
    len_list = list(map(len, str_list))
    for right in range(len(len_list) - 1, 0, -1):
        for left in range(right-1, -1, -1):
            if len_list[left] < len_list[right]:
                len_list[left] = len_list[right]
                str_list[left] = str_list[left].ljust(len_list[right])

    result = list(zip_longest(*str_list, fillvalue=''))
    return '\n'.join([''.join(x) for x in result])
