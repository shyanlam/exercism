def slices(series: str, length: int) -> list[str]:
    validation: dict[str, str] = {
        "length == 0": "slice length cannot be zero",
        "length < 0": "slice length cannot be negative",
        "len(series) == 0": "series cannot be empty",
        "len(series) < length": "slice length cannot be greater than series length"
    }
    for expression, message in validation.items():
        if eval(expression):
            raise ValueError(message)

    return [series[n: n + length] for n in range(len(series) - length + 1)]
