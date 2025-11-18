class Queen:
    MAX_ROW_INDEX = 7
    MAX_COLUMN_INDEX = 7

    def __init__(self, row: int, column: int):
        Queen.validate(row, Queen.MAX_ROW_INDEX, "row")
        Queen.validate(column, Queen.MAX_COLUMN_INDEX, "column")
        self.row = row
        self.column = column

    @staticmethod
    def validate(index: int, max_index: int, row_or_column: str):
        if index < 0:
            raise ValueError(f"{row_or_column} not positive")
        if index > max_index:
            raise ValueError(f"{row_or_column} not on board")

    def can_attack(self, another_queen) -> bool:
        if self.row == another_queen.row and self.column == another_queen.column:
            raise ValueError("Invalid queen position: both queens in the same square")
        return (self.row == another_queen.row or
                self.column == another_queen.column or
                abs(self.row - another_queen.row) == abs(self.column - another_queen.column))
