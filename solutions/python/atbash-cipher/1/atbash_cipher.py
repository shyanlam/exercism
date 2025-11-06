TEXT: str = "abcdefghijklmnopqrstuvwxyz"
DIGIT: str = "0123456789"
ATBASH_LOOKUP: dict[str, str] = dict(zip(TEXT, reversed(TEXT))) | dict(zip(DIGIT, DIGIT))

def translate(text: str) -> str:
    return ''.join([ATBASH_LOOKUP[char] for char in text.lower() if char in ATBASH_LOOKUP])

def encode(plain_text: str) -> str:
    result = translate(plain_text)
    return ' '.join(result[i : i + 5] for i in range(0, len(result), 5))


def decode(ciphered_text: str) -> str:
    return translate(ciphered_text)
