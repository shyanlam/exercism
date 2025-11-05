import re

def translate_word(word: str) -> str:
    result: str = ""
    # rule 1
    if re.match(r"^[aeiou]|xr|yt.*$", word) is not None:
        result = word
    # rule 3
    elif (rule3 := re.match(r"^([bcdfghjklmnpqrstvwxyz]*qu)(.*)$", word)) is not None:
        result = rule3.group(2) + rule3.group(1)

    # rule 4
    elif (rule4 := re.match(r"^(?:([bcdfghjklmnpqrstvwxyz]+)(y))(.*)$", word)) is not None:
        result = rule4.group(2) + rule4.group(3) + rule4.group(1)

    # rule 2
    elif (rule2 := re.match(r"^([bcdfghjklmnpqrstvwxyz]+)(.*)$", word)) is not None:
        result =  rule2.group(2) + rule2.group(1)

    return result + "ay"


def translate(text: str) -> str:
    words = text.split()
    return " ".join(map(translate_word, words))
