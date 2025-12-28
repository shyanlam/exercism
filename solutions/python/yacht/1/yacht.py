# Score categories.
# Change the values as you see fit.
from collections import Counter

ONES = 1
TWOS = 2
THREES = 3
FOURS = 4
FIVES = 5
SIXES = 6
FULL_HOUSE = 7
FOUR_OF_A_KIND = 8
LITTLE_STRAIGHT = 9
BIG_STRAIGHT = 10
CHOICE = 11
YACHT = 12


def score(dice: list[int], category: int):
    dice_count = Counter(dice)
    match category:
        case x if ONES <= x <= SIXES:
            return dice_count[x] * x

        case x if x == FULL_HOUSE:
            return (sum(dice)
                    if len(dice_count) == 2 and dice_count.most_common(1)[0][1] == 3
                    else 0)

        case x if x == FOUR_OF_A_KIND:
            return (dice_count.most_common(1)[0][0] * 4
                    if len(dice_count) <= 2 and dice_count.most_common(1)[0][1] >= 4
                    else 0)

        case x if x == LITTLE_STRAIGHT:
            return 30 if sorted(dice) == [1, 2, 3, 4, 5] else 0

        case x if x == BIG_STRAIGHT:
            return 30 if sorted(dice) == [2, 3, 4, 5, 6] else 0

        case x if x == CHOICE:
            return sum(dice)

        case x if x ==YACHT:
            return 50 if len(dice_count) == 1 else 0

        case _:
            assert False

score([4, 6, 2, 5, 3], BIG_STRAIGHT)