from collections import defaultdict
def is_isogram(string: str) -> bool:
    char_count = defaultdict(int)
    for ch in string.casefold():
        if ch.isalpha():
            char_count[ch] += 1

    return not any(value > 1 for value in char_count.values())
