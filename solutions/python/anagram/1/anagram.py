def is_anagram(word1: str, word2: str) -> bool:
    word1 = word1.casefold()
    word2 = word2.casefold()
    return word1 != word2 and sorted(list(word1)) == sorted(list(word2))

def find_anagrams(word: str, candidates: list[str]) -> list[str]:
    return [candidate for candidate in candidates if is_anagram(word, candidate)]
