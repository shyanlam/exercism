def tick(matrix: list[list[int]]) -> list[list[int]]:
    row_count = len(matrix)
    col_count = len(matrix[0]) if row_count > 0 else 0
    result: list[list[int | None]] = [[None for _ in range(col_count)] for _ in range(row_count)]
    for row in range(row_count):
        for col in range(col_count):
            life_neighbours = sum([1 for r in range(max(row - 1, 0), min(row + 2, row_count))
                                   for c in range(max(col - 1, 0), min(col + 2, col_count)) if
                                   (r != row or c != col) and matrix[r][c] == 1])
            if matrix[row][col] == 0 and life_neighbours == 3:
                result[row][col] = 1
            elif matrix[row][col] == 1 and 2 <= life_neighbours <= 3:
                result[row][col] = 1
            else:
                result[row][col] = 0
    return result
