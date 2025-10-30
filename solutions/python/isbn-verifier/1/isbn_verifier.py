import re

def is_valid(isbn: str) -> bool:
    isbn_compact = isbn.replace('-', '').casefold()
    if re.match(r"^\d{9}[\dx]$", isbn_compact) is None:
        return False

    check_sum: int = 0
    for index, ch in enumerate(isbn_compact, start=0):
        value = int(ch) if ch != 'x' else 10
        check_sum += value * (10 - index)
    return check_sum % 11 == 0
