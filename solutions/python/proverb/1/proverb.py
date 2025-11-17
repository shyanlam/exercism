def proverb(*words, **kwargs) -> list[str]:
    qualifier = ""
    for k, v in kwargs.items():
        if k == "qualifier" and v:
            qualifier = str(v) + " "

    result: list[str] = []
    if words:
        first, *rest = words
        while rest:
            second, *rest = rest
            result.append(f"For want of a {first} the {second} was lost.")
            first = second
        result.append(f"And all for the want of a {qualifier}{words[0]}.")

    return result
