def line_up(name: str, number: int) -> str:
    pattern = "{name}, you are the {number}{ordinal} customer we serve today. Thank you!"

    match (number % 100, number % 10):
        case (n, 1) if n != 11: ordinal = "st"
        case (n, 2) if n != 12: ordinal = "nd"
        case (n, 3) if n != 13: ordinal = "rd"
        case (_, _): ordinal = "th"

    return pattern.format(name = name, number = number, ordinal = ordinal)
