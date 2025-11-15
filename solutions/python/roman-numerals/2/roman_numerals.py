from unittest import case

ROMAN_NUMERALS: dict[int, str] = {
    1000: "M",
    900: "CM",
    500: "D",
    400: "CD",
    100: "C",
    90: "XC",
    50: "L",
    40: "XL",
    10: "X",
    9: "IX",
    5: "V",
    4: "IV",
    1: "I",
}


def roman(number: int) -> str:
    if not 0 < number <= 3999:
        raise ValueError("Value out of range")

    result = ""

    for arabic, roman_ in ROMAN_NUMERALS.items():
        if number >= arabic:
            result += roman_ * (number // arabic)
            number %= arabic

    return result
