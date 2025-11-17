def proverb(*words, qualifier = None) -> list[str]:
    result = [f"For want of a {first} the {second} was lost." for first, second in zip(words, words[1:])]
    if words:
        last_item = f"{qualifier} {words[0]}" if qualifier else words[0]
        result.append(f"And all for the want of a {last_item}.")

    return result

proverb()
proverb("neil")
proverb("neil", "horse")
