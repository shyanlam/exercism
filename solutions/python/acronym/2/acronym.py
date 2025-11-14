import re
def abbreviate(words: str) -> str:
    word_list = re.findall(r"[a-zA-Z']+", words)
    return "".join([word[0] for word in word_list]).upper()
