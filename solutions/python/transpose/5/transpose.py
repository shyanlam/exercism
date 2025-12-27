import itertools
from itertools import zip_longest

def transpose(text: str) -> str:
    marker = "\u0000"
    str_list = text.splitlines()

    result = zip_longest(*str_list, fillvalue=marker)
    result = [''.join(item).rstrip(marker).replace(marker, " ") for item in result]
    return "\n".join(result)

