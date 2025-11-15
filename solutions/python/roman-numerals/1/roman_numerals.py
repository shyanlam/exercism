from unittest import case


def roman_numeral(number: int, one: str, five: str, ten: str) -> str:
    match number:
        case num if num in (1, 2, 3):
            return one * num
        case 4:
            return one + five
        case num if num in (5, 6, 7, 8):
            return five + (one * (num - 5))
        case 9:
            return one + ten
        case _:
            return ""


def roman(number: int) -> str:
    if not 0 < number <= 3999:
        raise ValueError("Value out of range")

    num_str = f"{number:04}"
    thousands = int(num_str[0])
    hundreds = int(num_str[1])
    tens = int(num_str[2])
    ones = int(num_str[3])

    return (roman_numeral(thousands, "M", "", "") +
            roman_numeral(hundreds, "C", "D", "M") +
            roman_numeral(tens, "X", "L", "C") +
            roman_numeral(ones, "I", "V", "X"))
