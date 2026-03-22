from itertools import cycle


def spiral_matrix(size) -> list[list[int]]:
    matrix: list[list[int]] = [[0] * size for _ in range(size)]
    movement = cycle(((0, 1),  # left to right
                      (1, 0),  # top to bottom
                      (0, -1),  # right to left
                      (-1, 0)  # bottom to top
                      ))
    move_row, move_col = next(movement)
    row, col = 0, 0
    for value in range(size * size):
        matrix[row][col] = value + 1
        if not ((0 <= row + move_row < size) and
                (0 <= col + move_col < size) and
                matrix[row + move_row][col + move_col] == 0):
            move_row, move_col = next(movement)
        row += move_row
        col += move_col

    return matrix
