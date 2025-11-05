"""
This exercise stub and the test suite contain several enumerated constants.

Enumerated constants can be done with a NAME assigned to an arbitrary,
but unique value. An integer is traditionally used because it’s memory
efficient.
It is a common practice to export both constants and functions that work with
those constants (ex. the constants in the os, subprocess and re modules).

You can learn more here: https://en.wikipedia.org/wiki/Enumerated_type
"""

# Possible sublist categories.
# Change the values as you see fit.
SUBLIST = 1
SUPERLIST = 2
EQUAL = 3
UNEQUAL = 4


def is_superlist(long_list: list, short_list: list) -> bool:
    assert (long_len := len(long_list)) > (short_len := len(short_list))

    if short_len == 0:
        return True

    for n in [index for index, value in enumerate(long_list) if value == short_list[0]]:
        if long_list[n: n + short_len] == short_list:
            return True

    return False


def sublist(list_one: list, list_two: list) -> int:
    diff: int = len(list_one) - len(list_two)
    match diff:
        case 0: return EQUAL if list_one == list_two else UNEQUAL
        case _ if diff > 0: return SUPERLIST if is_superlist(list_one, list_two) else UNEQUAL
        case _ : return SUBLIST if is_superlist(list_two, list_one) else UNEQUAL
