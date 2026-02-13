import re
import string
import math


def calc_rect(area: int) -> tuple[int, int]:
    side = math.sqrt(area)
    r, c = math.floor(side), math.ceil(side)
    return (r, c) if r * c >= area else (r + 1, c)


def cipher_text(plain_text: str) -> str:
    packed_text = re.sub(rf"[{string.punctuation}\s]", "", plain_text).lower()
    r, c = calc_rect(len(packed_text))
    packed_text = packed_text.ljust(r * c)
    rect_text = [list(packed_text[n: n + c]) for n in range(0, len(packed_text), max(1, c))]
    transposed_rect = list(zip(*rect_text))
    return " ".join(["".join(row) for row in transposed_rect])
