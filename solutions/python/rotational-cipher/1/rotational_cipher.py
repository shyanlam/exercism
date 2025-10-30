import string

PLAIN_TEXT_LC: str = string.ascii_lowercase
PLAIN_TEXT_UC: str = string.ascii_uppercase
PLAIN_TEXT: str = PLAIN_TEXT_LC + PLAIN_TEXT_UC

def rotate(text: str, key: int) -> str:
    if not 0 <= key <= len(PLAIN_TEXT_LC):
        raise ValueError('Key must be between 0 and {len(PLAIN_TEXT)}')

    cipher_text = PLAIN_TEXT_LC[key:]+PLAIN_TEXT_LC[:key]+PLAIN_TEXT_UC[key:]+PLAIN_TEXT_UC[:key]
    trans = str.maketrans(PLAIN_TEXT, cipher_text)
    return text.translate(trans)
