import string


def is_pangram(sentence: str) -> bool:
    return len(set(ch.casefold() for ch in sentence if ch.isalpha())) == len(string.ascii_lowercase)
