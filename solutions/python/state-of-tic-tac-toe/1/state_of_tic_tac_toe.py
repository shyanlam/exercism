from collections import Counter


def gamestate(board: list[str]) -> str:
    #   [0][0] | [0][1] | [0][2]
    # ---------+--------+---------
    #   [1][0] | [1][1] | [1][2]
    # ---------+--------+---------
    #   [2][0] | [2][1] | [2][2]
    xo_count = Counter([x for row in board for x in row])
    diff = xo_count['X'] - xo_count['O']
    if diff < 0:
        raise ValueError("Wrong turn order: O started")
    elif diff > 1:
        raise ValueError("Wrong turn order: X went twice")

    win_state: dict[str, int] = {'X': 0, 'O': 0}
    # ['xxx', ...] --> [['x', 'x,', 'x], ...]
    board2 = [list(row) for row in board]
    # check row
    for counter in [Counter(row).most_common() for row in board2]:
        if len(counter) == 1 and counter[0][0] != ' ':
            win_state[counter[0][0]] += 1

    # rotate board and check row
    for counter in [Counter(row).most_common() for row in list(zip(*board2))]:
        if len(counter) == 1 and counter[0][0] != ' ':
            win_state[counter[0][0]] += 1

    # check diagonal
    #   [0][0] | [0][1] | [0][2]
    # ---------+--------+---------
    #   [1][0] | [1][1] | [1][2]
    # ---------+--------+---------
    #   [2][0] | [2][1] | [2][2]

    if (center := board2[1][1]) != ' ':
        if center == board2[0][0] == board2[2][2]:
            win_state[center] += 1
        if center == board2[0][2] == board2[2][0]:
            win_state[center] += 1

    match (win_state['X'], win_state['O'], xo_count[' ']):
        case (x, o, _) if (x > 0) != (o > 0):
            return "win"
        case (x, o, _) if x > 0 and o > 0:
            raise ValueError("Impossible board: game should have ended after the game was won")
        case (_, _, sp):
            return "ongoing" if sp > 0 else "draw"

