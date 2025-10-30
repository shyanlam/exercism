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

    factors: list[int] = [x for x in range(1, number // 2 + 1) if number % x == 0]
    match sum(factors):
        case aliquot_sum if number < aliquot_sum: return CLASS_ABUNDANT
        case aliquot_sum if number > aliquot_sum: return CLASS_DEFICIENT
        case _:  return CLASS_PERFECT
