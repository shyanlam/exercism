def is_paired(input_string: str) -> bool:
    stack: list[str] = []
    MATCHING_BRACKETS: dict[str, str] = {
        "}": "{",
        "]": "[",
        ")": "("
    }
    for char in input_string:
        if char in MATCHING_BRACKETS.values():
            stack.append(char)
        elif char in MATCHING_BRACKETS.keys():
            if stack == [] or MATCHING_BRACKETS[char] != stack.pop():
                return False

    return stack == []