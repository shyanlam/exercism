LETTER_SCORE: dict[str, int] = {
    **dict.fromkeys("AEIOULNRST", 1),
    **dict.fromkeys("DG", 2),
    **dict.fromkeys("BCMP", 3),
    **dict.fromkeys("FHVWY", 4),
    **dict.fromkeys("K", 5),
    **dict.fromkeys("JX", 8),
    **dict.fromkeys("QZ", 10),
}


def score(word):
    return sum(LETTER_SCORE[letter] for letter in word.upper())
