# Score categories.
# Change the values as you see fit.
from collections import Counter
from enum import auto, Enum
from typing import Callable

class Yacht(Enum):
    ONES = auto()
    TWOS = auto()
    THREES = auto()
    FOURS = auto()
    FIVES = auto()
    SIXES = auto()
    FULL_HOUSE = auto()
    FOUR_OF_A_KIND = auto()
    LITTLE_STRAIGHT = auto()
    BIG_STRAIGHT = auto()
    CHOICE = auto()
    YACHT = auto()

ONES = Yacht.ONES
TWOS = Yacht.TWOS
THREES = Yacht.THREES
FOURS = Yacht.FOURS
FIVES = Yacht.FIVES
SIXES = Yacht.SIXES
FULL_HOUSE = Yacht.FULL_HOUSE
FOUR_OF_A_KIND = Yacht.FOUR_OF_A_KIND
LITTLE_STRAIGHT = Yacht.LITTLE_STRAIGHT
BIG_STRAIGHT = Yacht.BIG_STRAIGHT
CHOICE = Yacht.CHOICE
YACHT = Yacht.YACHT

def score(dice: list[int], category: Yacht) -> int:
    match category:
        case x if YACHT.ONES.value <= x.value <= YACHT.SIXES.value :
            return Counter(dice)[x.value] * x.value

        case YACHT.FULL_HOUSE:
            return sum(dice) if sorted(Counter(dice).values()) == [2, 3] else 0

        case Yacht.FOUR_OF_A_KIND:
            four_dice = [x for x in set(dice) if dice.count(x) >= 4]
            return four_dice[0] * 4 if four_dice else 0

        case Yacht.LITTLE_STRAIGHT:
            return 30 if sorted(dice) == [1, 2, 3, 4, 5] else 0

        case Yacht.BIG_STRAIGHT:
            return 30 if sorted(dice) == [2, 3, 4, 5, 6] else 0

        case Yacht.CHOICE:
            return sum(dice)

        case Yacht.YACHT:
            return 50 if len(set(dice)) == 1 else 0

        case _:
            assert False
