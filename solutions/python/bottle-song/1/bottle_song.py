from unittest import result

COUNT = ["no", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten"]

LINES = (
    "{0} green {1} hanging on the wall,\n"
    "{0} green {1} hanging on the wall,\n"
    "And if one green bottle should accidentally fall,\n"
    "There'll be {2} green {3} hanging on the wall."
)

def bottle(num: int) -> str:
    return "bottles" if num == 0 or num > 1 else "bottle"

def recite(start: int, take: int = 1) -> list[str]:
    result = ""
    for n in range(start, start - take, -1):
        if result != "":
            result += "\n\n"
        result += LINES.format(COUNT[n], bottle(n),
                               COUNT[n - 1].lower(), bottle(n - 1))

    return result.splitlines()
