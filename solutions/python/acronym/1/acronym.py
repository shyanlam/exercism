import re
def abbreviate(words: str) -> str:
    words = words.replace("'", "")
    words = re.sub(r"[^a-zA-Z]", " ", words)
    return "".join([word[0] for word in words.split()]).upper()
