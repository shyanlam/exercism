def fill_one_cycle(matrix: list[list[int]], start: int, end: int, value: int) -> int:
    row, col = start, start

    # top: left -> right
    for _col in range(col, end):
        matrix[row][_col] = value
        value += 1

    # right: top -> bottom
    col = end
    for _row in range(row, end):
        matrix[_row][col] = value
        value += 1

    # bottom: right -> left
    row = end
    for _col in range(end, start, -1):
        matrix[row][_col] = value
        value += 1

    # left -> bottom -> top
    col = start
    for _row in range(end, start, -1):
        matrix[_row][col] = value
        value += 1

    return value


def spiral_matrix(size) -> list[list[int]]:
    matrix: list[list[int]] = [[0] * size for _ in range(size)]
    start, end = 0, size - 1
    value = 1
    while start < end:
        value = fill_one_cycle(matrix, start, end, value)
        start += 1
        end -= 1
    if start == end:
        matrix[start][end] = value
    return matrix
