RESISTORS_COLOR_CODE: dict[str, int] = {
    "black": 0,
    "brown": 1,
    "red": 2,
    "orange": 3,
    "yellow": 4,
    "green": 5,
    "blue": 6,
    "violet": 7,
    "grey": 8,
    "white": 9,
}

def value(colors: list[str]):
    return RESISTORS_COLOR_CODE[colors[0]] * 10 + RESISTORS_COLOR_CODE[colors[1]]

