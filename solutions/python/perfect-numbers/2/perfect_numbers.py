CLASS_PERFECT: str = "perfect"
CLASS_ABUNDANT: str = "abundant"
CLASS_DEFICIENT: str = "deficient"


def classify(number: int) -> str:
    """ A perfect number equals the sum of its positive divisors.

    :param number: int a positive integer
    :return: str the classification of the input integer
    """
    if number < 1:
        raise ValueError("Classification is only possible for positive integers.")

    aliquot_sum: int = 0
    for n in range(1, number // 2 + 1):
        aliquot_sum += n if number % n == 0 else 0

    return CLASS_PERFECT if aliquot_sum == number else (
        CLASS_ABUNDANT if aliquot_sum > number else CLASS_DEFICIENT)
