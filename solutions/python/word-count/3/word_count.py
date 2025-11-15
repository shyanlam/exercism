from collections import defaultdict
import re
def count_words(sentence: str) -> dict[str, int]:
    re_word = re.compile(r"[a-z\d]+(?:'[a-z]+)?")
    words = re_word.findall(sentence.lower())
    result: defaultdict[str, int] = defaultdict(int)
    for word in words:
        result[word] += 1
    return dict(result)

