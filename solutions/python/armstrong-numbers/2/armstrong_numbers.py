def is_armstrong_number(number: int) -> bool:
    length: int = len(str(number))
    digits: list[int] = [int(x) for x in str(number)]
    return sum([x ** length for x in digits]) == number

