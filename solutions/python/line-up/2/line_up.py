def line_up(name: str, number: int) -> str:
    pattern = "{name}, you are the {number}{ordinal} customer we serve today. Thank you!"

    if 11 <= number % 100 <= 13:
        ordinal = "th"
    else:
        ordinal = ["th", "st", "nd", "rd", "th"][min(number % 10, 4)]

    return pattern.format(name = name, number = number, ordinal = ordinal)
