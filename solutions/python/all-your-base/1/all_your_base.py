def rebase(input_base: int, digits: list[int], output_base:int) -> list[int]:
    if input_base < 2:
        raise ValueError("input base must be >= 2")
    if any(not (0 <= d < input_base) for d in digits):
        raise ValueError("all digits must satisfy 0 <= d < input base")
    if output_base < 2:
        raise ValueError("output base must be >= 2")

    base10 = 0
    for d in digits:
        base10 = base10 * input_base + d

    result: list[int] = []
    while True:
        quotient, remainder = divmod(base10, output_base)
        result.append(remainder)
        if (base10 := quotient) == 0:
            break

    return result[::-1]

