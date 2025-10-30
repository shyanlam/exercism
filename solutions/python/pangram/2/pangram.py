import string


def is_pangram(sentence: str) -> bool:
    sentence = sentence.casefold()
    for ch in string.ascii_lowercase:
        if ch not in sentence:
            return False
    return True
