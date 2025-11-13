NUMBER_NAME: dict[int, str] = {
    1: 'one', 2: 'two', 3: 'three', 4: 'four', 5: 'five', 6: 'six', 7: 'seven', 8: 'eight', 9: 'nine',
    10: 'ten', 11: 'eleven', 12: 'twelve', 13: 'thirteen', 14: 'fourteen', 15: 'fifteen', 16: 'sixteen',
    17: 'seventeen', 18: 'eighteen', 19: 'nineteen',
    20: 'twenty', 30: 'thirty', 40: 'forty', 50: 'fifty', 60: 'sixty', 70: 'seventy', 80: 'eighty', 90: 'ninety',
}

SCALE: dict[int, str] = {1_000_000_000: "billion", 1_000_000: "million", 1_000: "thousand"}


def say_ddd(number: int, scale: str = "") -> list[str]:
    assert 0 <= number < 1000
    result: list[str] = []
    if hundreds := number // 100:
        result.append(f"{NUMBER_NAME[hundreds]} hundred")

    if 0 < (number := number % 100) < 20:
        result.append(f"{NUMBER_NAME[number]}")
    else:
        if tens := number // 10 * 10:
            result.append(f"{NUMBER_NAME[tens]}")
        if unit := number % 10:
            result[-1] += f"-{NUMBER_NAME[unit]}"

    if scale:
        result.append(scale)
    return result


def say(number: int) -> str:
    if not (0 <= number < 999_999_999_999):
        raise ValueError("input out of range")

    if number == 0:
        return "zero"

    result: list[str] = list()
    for scale_num, scale_name in SCALE.items():
        if value := number // scale_num:
            result.extend(say_ddd(value, scale_name))
            number %= scale_num

    result.extend(say_ddd(number))
    return " ".join(result)
