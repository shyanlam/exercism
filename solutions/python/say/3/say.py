NUMBER_NAME: dict[int, str] = {
    0: 'zero',
    1: 'one', 2: 'two', 3: 'three', 4: 'four', 5: 'five', 6: 'six', 7: 'seven', 8: 'eight', 9: 'nine',
    10: 'ten', 11: 'eleven', 12: 'twelve', 13: 'thirteen', 14: 'fourteen', 15: 'fifteen', 16: 'sixteen',
    17: 'seventeen', 18: 'eighteen', 19: 'nineteen',
}

TENS: dict[int, str] = {
    1: 'ten', 2: 'twenty', 3: 'thirty', 4: 'forty', 5: 'fifty',
    6: 'sixty', 7: 'seventy', 8: 'eighty', 9: 'ninety',
}


def say_hundreds(number: int) -> str:
    assert 0 <= number < 1000

    num_str: list[str] = []

    hundred, rest = divmod(number, 100)
    if hundred:
        num_str.append(f"{NUMBER_NAME[hundred]} hundred")

    if 0 < rest < 20:
        num_str.append(NUMBER_NAME[rest])
    else:
        tens, unit = divmod(rest, 10)
        if tens:
            num_str.append(TENS[tens])
        if unit:
            num_str[-1] += f"-{NUMBER_NAME[unit]}"

    return " ".join(num_str)


SCALE: dict[int, str] = {
    1_000_000_000_000: "trillion",
    1_000_000_000: "billion",
    1_000_000: "million",
    1_000: "thousand",
}


def say(number: int) -> str:
    if not (0 <= number < 999_999_999_999):
        raise ValueError("input out of range")

    if number == 0:
        return "zero"

    result: list[str] = []
    for scale, name in SCALE.items():
        if number:
            num, rest = divmod(number, scale)
            if num:
                result.append(f"{say_hundreds(num)} {name}")
            number = rest

    if number:
        result.append(f"{say_hundreds(number)}")

    return " ".join(result)

