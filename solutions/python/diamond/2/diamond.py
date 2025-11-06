def rows(letter: str) -> list[str]:
    half_diamond = [chr(n) for n in range(ord('A'), ord(letter) + 1)]
    half_line = list(reversed(half_diamond))
    diamond = half_diamond + half_diamond[-2::-1]
    line = half_line + half_line[-2::-1]

    return ["".join([c if c == d else ' ' for c in line]) for d in diamond]

