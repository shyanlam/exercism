import re
def is_paired(input_string: str) -> bool:
    input_string = re.sub(r"[^{}[\]()]", "", input_string)
    replaced: bool = True
    while replaced:
        input_string, replaced = re.subn(r"{}|\[\]|\(\)", "", input_string)

    return input_string == ""