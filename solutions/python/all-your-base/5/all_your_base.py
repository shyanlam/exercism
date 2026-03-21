""" base conversion """


def rebase(input_base: int, digits: list[int], output_base: int) -> list[int]:
    """ Convert any digit in any base to another base"""

    if input_base < 2:
        raise ValueError("input base must be >= 2")
    if any(not (0 <= digit < input_base) for digit in digits):
        raise ValueError("all digits must satisfy 0 <= d < input base")
    if output_base < 2:
        raise ValueError("output base must be >= 2")

    base10 = 0
    for digit in digits:
        base10 = base10 * input_base + digit

    result: list[int] = []
    while True:
        quotient, remainder = divmod(base10, output_base)
        result.append(remainder)
        if (base10 := quotient) == 0:
            break

    return result[::-1]
