import unittest
import re
from collections import defaultdict
from itertools import combinations
from typing import Iterable, Counter, Any, Generator


def get_corners(line: str) -> list[list[int]]:
    h_pattern = re.compile(r"(\+\-*\+(\-*\+)*)")
    result: list[list[int]] = []
    pos = 0
    while (m := h_pattern.search(line, pos)) is not None:
        result.append([n for n in range(m.span()[0], m.span()[1]) if line[n] == '+'])
        pos = m.span()[1] - 1
    return result


def is_rect(lines: list[str], corner: tuple[int, int]) -> bool:
    for line in lines:
        if line[corner[0]] not in ['|', '+'] or line[corner[1]] not in ['|', '+']:
            return False
    return True


def rectangles(strings: list[str]) -> int:
    corner_line: defaultdict[tuple[int, int], list[int]] = defaultdict(list)

    for l, line in enumerate(strings):
        for corner in get_corners(line):
            for c in combinations(corner, 2):
                corner_line[c].append(l)

    count: int = 0
    for corner, line_nos in corner_line.items():
        start_ends = list(combinations(line_nos, 2))
        for se in start_ends:
            if is_rect(strings[se[0] + 1: se[1]], corner):
                count += 1

    return count


