def is_isogram(string: str) -> bool:
    string = [ch for ch in string.casefold() if ch.isalpha()]
    return len(string) == len(set(string))
