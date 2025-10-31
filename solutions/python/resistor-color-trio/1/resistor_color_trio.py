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

def label(colors: list[str]) -> str:
    value: int = (RESISTORS_COLOR_CODE[colors[0]] * 10 +
                  RESISTORS_COLOR_CODE[colors[1]]) * 10 ** RESISTORS_COLOR_CODE[colors[2]]
    value_str: str = str(value)
    match value_str:
        case s if s.endswith("000000000"):
            return s[:-9] + " gigaohms"
        case s if s.endswith("000000"):
            return s[:-6] + " megaohms"
        case s if s.endswith("000"):
            return s[:-3] + " kiloohms"
        case _:
            return value_str + " ohms"




