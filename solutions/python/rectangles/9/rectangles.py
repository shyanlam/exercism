import re
from collections import defaultdict
from itertools import combinations


def get_vertices(line: str) -> list[list[int]]:
    h_pattern = re.compile(r"(\+\-*\+(\-*\+)*)")
    result: list[list[int]] = []
    pos = 0
    while (match := h_pattern.search(line, pos)) is not None:
        result.append([pos for pos in range(match.span()[0], match.span()[1]) if line[pos] == "+"])
        pos = match.span()[1] - 1
    return result


def is_rect(lines: list[str], corner: tuple[int, int]) -> bool:
    return all(line[corner[0]] in "|+" and line[corner[1]] in "|+" for line in lines)


def rectangles(strings: list[str]) -> int:
    vertices_lines: defaultdict[tuple[int, int], list[int]] = defaultdict(list)

    for l, line in enumerate(strings):
        for vertices in get_vertices(line):
            for v in combinations(vertices, 2):
                vertices_lines[v].append(l)

    count: int = 0
    for vertices, line_nos in vertices_lines.items():
        start_ends = list(combinations(line_nos, 2))
        for se in start_ends:
            if is_rect(strings[se[0] + 1: se[1]], vertices):
                count += 1

    return count
