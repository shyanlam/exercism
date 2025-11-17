from collections import Counter
import re


def count_words(sentence: str) -> dict[str, int]:
    re_word = re.compile(r"[a-z\d]+(?:'[a-z]+)?")
    words = re_word.findall(sentence.lower())
    return dict(Counter(words))
