import re


class ConnectGame:
    """ Determine winner of the game Hex
        Player 'O' top to bottom
        Player 'X' left to right
    """

    def __init__(self, board):
        board_list = board.split("\n")
        self.board = [row.replace(" ", "") for row in board_list]
        self.flipped_board = ["".join(row) for row in zip(*self.board)]

    @staticmethod
    def get_adjacent_cells(cell: tuple[int, int], cell_positions: set[tuple[int, int]]) -> set[tuple[int, int]]:
        # r-1 [ (r-1,c-1) (r-1,c) (r-1,c+1)  ...
        #                     \      /
        #  r  [      (r,c-1) < (r,c) > (r,c+1) ...
        #                     /     \
        # r+1 [         (r+1,c-1)  (r+1,c)  (r+1,c+1) ...
        result: set[tuple[int, int]] = set()
        r, c = cell
        for adj in [(r - 1, c), (r - 1, c + 1), (r, c - 1), (r, c + 1), (r + 1, c - 1), (r + 1, c)]:
            if adj in cell_positions:
                result.add(adj)
        return result

    @staticmethod
    def connect_vertically(board: list[str], player: str) -> bool:
        player_board_pos: set[tuple[int, int]] = set()
        for r, row in enumerate(board):
            matches = re.finditer(player, row)
            for match in matches:
                player_board_pos.add((r, match.start()))

        top_cells = [(r, c) for r, c in player_board_pos if r == 0]
        bottom_cells = [(r, c) for r, c, in player_board_pos if r == len(board) - 1]
        if len(top_cells) == 0 or len(bottom_cells) == 0:
            return False

        for top_cell in top_cells:
            checked: set[tuple[int, int]] = set()
            player_cells: set[tuple[int, int]] = {top_cell}
            added = True
            while added:
                adjacent_cells: set[tuple[int, int]] = set()
                added = False
                for cell in player_cells:
                    if cell not in checked:
                        adjacent_cells.update(ConnectGame.get_adjacent_cells(cell, player_board_pos))
                        checked.add(cell)
                        added = True
                player_cells.update(adjacent_cells)

            if any([cell[0] == len(board) - 1 for cell in player_cells]):
                return True

        return False

    def get_winner(self) -> str:
        if len(self.board) == 0:
            return ""

        if ConnectGame.connect_vertically(self.board, "O"):
            return "O"
        if ConnectGame.connect_vertically(self.flipped_board, "X"):
            return "X"
        return ""
