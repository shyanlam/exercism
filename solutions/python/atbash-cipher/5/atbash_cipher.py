ALPHA: str = "abcdefghijklmnopqrstuvwxyz"
DIGIT: str = "0123456789"
ATBASH_TRANSLATE = str.maketrans(ALPHA + DIGIT, ALPHA[::-1] + DIGIT)

def translate(text: str) -> str:
    return ''.join(char.translate(ATBASH_TRANSLATE) for char in text.lower() if str.isalnum(char))

def encode(plain_text: str) -> str:
    result = translate(plain_text)
    return ' '.join(result[i : i + 5] for i in range(0, len(result), 5))


def decode(ciphered_text: str) -> str:
    return translate(ciphered_text)
