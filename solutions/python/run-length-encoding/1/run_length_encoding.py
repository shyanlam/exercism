import re
def decode(rle: str) -> str:
    text: str = ""
    items = re.findall(r"(?:(\d*)(.))", rle)
    print(f"{items = }")
    for count, ch in items:
        count: int = int(count) if count else 1
        print(f"{count = }, {ch = }")
        text += count * ch
    return text



def encode(text: str) -> str:
    rle: str = ""
    cur_char = ""
    cur_length = 0
    for char in text:
        if char == cur_char:
            cur_length += 1
        else:
            if cur_char != "":
                if cur_length > 1:
                    rle += f"{cur_length}{cur_char}"
                else:
                    rle += cur_char
            cur_char = char
            cur_length = 1
    if cur_char != "":
        if cur_length > 1:
            rle += f"{cur_length}{cur_char}"
        else:
            rle += cur_char

    return rle