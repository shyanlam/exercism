def encode(numbers: list[int]) -> list[int]:
    result: list[int] = []
    for number in numbers:
        encoded_numbers: list[int] = []
        encoded_numbers.insert(0, number & 0x7F)
        while (number := number >> 7) != 0:
            encoded_numbers.insert(0, number & 0x7F | 0x80)
        result += encoded_numbers
    return result


def decode(bytes_: list[int]) -> list[int]:
    if (bytes_[-1] & 0x80) != 0:
        raise ValueError("incomplete sequence")

    result: list[int] = []
    value = 0
    for byte in bytes_:
        value = (value << 7) | (byte & 0x7F)
        if byte & 0x80 == 0:
            result.append(value)
            value = 0
    return result
