def saddle_points(matrix: list[list[int]]) -> list[dict[str, int]]:
    if any(len(row) != len(matrix[0]) for row in matrix):
        raise ValueError("irregular matrix")

    saddle_result: list[dict[str, int]] = []
    row_count = len(matrix)
    for r, row in enumerate(matrix):
        tallest = max(row)
        tallest_cols = [n for n, v in enumerate(row) if v == tallest]
        for c in tallest_cols:
            column = [matrix[r][c] for r in range(row_count)]
            if matrix[r][c] == min(column):
                saddle_result.append({"row": r + 1, "column": c+1})

    return saddle_result
