from collections import Counter


def gamestate(board: list[str]) -> str:
    #  [0][0] | [0][1] | [0][2]
    # --------+--------+--------
    #  [1][0] | [1][1] | [1][2]
    # --------+--------+--------
    #  [2][0] | [2][1] | [2][2]

    counter = Counter("".join(board))
    if (diff := counter['X'] - counter['O']) < 0:
        raise ValueError("Wrong turn order: O started")
    elif diff > 1:
        raise ValueError("Wrong turn order: X went twice")

    rotate_board = ["".join(col) for col in list(zip(*board))]
    diagonals = [board[0][0] + board[1][1] + board[2][2],
                 board[0][2] + board[1][1] + board[2][0]]
    total = board + rotate_board + diagonals

    x_win = "XXX" in total
    o_win = "OOO" in total
    if x_win and o_win:
        raise ValueError("Impossible board: game should have ended after the game was won")
    if x_win or o_win:
        return "win"
    return "draw" if counter[' '] == 0 else "ongoing"
