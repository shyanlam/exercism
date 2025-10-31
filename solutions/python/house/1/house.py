NOUNS_VERBS: list[tuple[str, str]] = [
    ("house that Jack built.", ""),
    ("malt", "lay in",),
    ("rat", "ate",),
    ("cat", "killed",),
    ("dog", "worried",),
    ("cow with the crumpled horn", "tossed",),
    ("maiden all forlorn", "milked",),
    ("man all tattered and torn", "kissed",),
    ("priest all shaven and shorn", "married",),
    ("rooster that crowed in the morn", "woke",),
    ("farmer sowing his corn", "kept",),
    ("horse and the hound and the horn", "belonged to"),
]

def recite_verse(verse: int) -> str:
    result = list()
    result.append(f"This is the {NOUNS_VERBS[verse-1][0]}")
    for n in reversed(range(0, verse)):
        if n > 0:
            result.append(f"that {NOUNS_VERBS[n][1]} the {NOUNS_VERBS[n-1][0]}")
    return " ".join(result)

def recite(start_verse: int, end_verse: int) -> list[str]:
    result: list[str] = list()
    for verse in range(start_verse, end_verse+1):
        result.append(recite_verse(verse))

    return result

