from collections import Counter


def gamestate(board: list[str]) -> str:
    flatten_board = [x for row in board for x in row]
    xo_count = Counter(flatten_board)
    diff = xo_count['X'] - xo_count['O']
    if diff < 0:
        raise ValueError("Wrong turn order: O started")
    elif diff > 1:
        raise ValueError("Wrong turn order: X went twice")

    win_state: dict[str, int] = {'X': 0, 'O': 0}

    #   [0] | [1] | [2]
    # ------+-----+------
    #   [3] | [4] | [5]
    # ------+-----+------
    #   [6] | [7] | [8]
    win_cells: dict[int, list[tuple[int, int]]] = {
        0: [(1, 2), (3, 6)],
        4: [(3, 5), (1, 7), (2, 6), (0, 8)],
        8: [(6, 7), (2, 5)]
    }
    win_state: dict[str, int] = {'X': 0, 'O': 0}
    for n0, cells in win_cells.items():
        if (x_o := flatten_board[n0]) != ' ':
            for n2 in cells:
                if x_o == flatten_board[n2[0]] == flatten_board[n2[1]]:
                    win_state[x_o] += 1

    match (win_state['X'], win_state['O'], xo_count[' ']):
        case (x, o, _) if (x > 0) != (o > 0):
            return "win"
        case (x, o, _) if x > 0 and o > 0:
            raise ValueError("Impossible board: game should have ended after the game was won")
        case (_, _, sp):
            return "ongoing" if sp > 0 else "draw"

