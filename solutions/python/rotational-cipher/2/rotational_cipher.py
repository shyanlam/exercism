import string

alpha: str = string.ascii_lowercase

def rotate(text: str, key: int) -> str:
    if not 0 <= key <= len(alpha):
        raise ValueError('Key must be between 0 and {len(PLAIN_TEXT)}')

    crypt = alpha[key:] + alpha[:key]
    trans = str.maketrans(alpha + alpha.upper(), crypt + crypt.upper())
    return text.translate(trans)
