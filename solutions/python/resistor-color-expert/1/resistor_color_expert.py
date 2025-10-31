from unittest import case

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

TOLERANCE_BAND: dict[str, str] = {
    "grey": " ±0.05%",
    "violet": " ±0.1%",
    "blue": " ±0.25%",
    "green": " ±0.5%",
    "brown": " ±1%",
    "red": " ±2%",
    "gold": " ±5%",
    "silver": " ±10%",
}

def resistor_label(colors: list[str]) -> str:

    value: int = 0
    for index, color in enumerate(colors):
        if index < 2:
            value = value * 10 + RESISTORS_COLOR_CODE[color]
        else:
            break

    tolerance: str = ""
    if len(colors) == 4:
        value = value * 10 ** RESISTORS_COLOR_CODE[colors[2]]
        tolerance = TOLERANCE_BAND[colors[3]]
    elif len(colors) == 5:
        value = value * 10 + RESISTORS_COLOR_CODE[colors[2]]
        value = value * 10 ** RESISTORS_COLOR_CODE[colors[3]]
        tolerance = TOLERANCE_BAND[colors[4]]

    metrix_prefix: str = ""
    if value >= 1_000_000_000:
        value /= 1_000_000_000
        metrix_prefix = "gigaohms"
    elif value >= 1_000_000:
        value /= 1_000_000
        metrix_prefix = "megaohms"
    elif value >= 1_000:
        value /= 1_000
        metrix_prefix = "kiloohms"
    else:
        metrix_prefix = "ohms"

    return f"{value:g} {metrix_prefix}{tolerance}"
