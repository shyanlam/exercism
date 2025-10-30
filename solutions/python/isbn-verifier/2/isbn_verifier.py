import re

def is_valid(isbn: str) -> bool:
    isbn_compact = isbn.replace('-', '').casefold()
    if re.match(r"^\d{9}[\dx]$", isbn_compact) is None:
        return False

    digits: list[int] = [ch == 'x' and 10 or int(ch) for ch in isbn_compact]
    check_sum = sum(digit * (10-n) for n, digit in enumerate(digits))
    return check_sum % 11 == 0
