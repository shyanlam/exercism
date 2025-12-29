def saddle_points(matrix: list[list[int]]) -> list[dict[str, int]]:
    if any(len(row) != len(matrix[0]) for row in matrix):
        raise ValueError("irregular matrix")

    row_count = len(matrix)
    rows_max = list(map(max, matrix))
    cols_min = list(map(min, zip(*matrix)))
    return [{"row": r+1, "column": c+1}
            for r, row_max in enumerate(rows_max)
            for c, col_min in enumerate(cols_min) if row_max == col_min]
