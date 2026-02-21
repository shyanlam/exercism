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

    for line_no, line in enumerate(strings):
        for vertices_list in get_vertices(line):
            for vertices in combinations(vertices_list, 2):
                vertices_lines[vertices].append(line_no)

    count: int = 0
    for vertices, line_nos in vertices_lines.items():
        start_ends = list(combinations(line_nos, 2))
        for line_range in start_ends:
            if is_rect(strings[line_range[0] + 1: line_range[1]], vertices):
                count += 1

    return count
