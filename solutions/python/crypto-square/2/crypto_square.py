import re
import string
import math


def cipher_text(plain_text: str) -> str:
    packed_text = re.sub(rf"[{string.punctuation}\s]", "", plain_text).lower()
    c = math.ceil(math.sqrt(len(packed_text)))
    r = math.ceil(len(packed_text) / c) if c else 0
    packed_text = packed_text.ljust(r * c)
    return " ".join([packed_text[n::c] for n in range(c)])
