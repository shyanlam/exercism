# Score categories.
# Change the values as you see fit.
from collections import Counter
from typing import Callable

ONES = lambda dice: single_digit(dice, 1)
TWOS = lambda dice: single_digit(dice, 2)
THREES = lambda dice: single_digit(dice, 3)
FOURS = lambda dice: single_digit(dice, 4)
FIVES = lambda dice: single_digit(dice, 5)
SIXES = lambda dice: single_digit(dice, 6)
FULL_HOUSE = lambda dice: sum(dice) if sorted(Counter(dice).values()) == [2, 3] else 0
FOUR_OF_A_KIND = lambda dice: four_of_a_kind(dice)
LITTLE_STRAIGHT = lambda dice: 30 if sorted(dice) == [1, 2, 3, 4, 5] else 0
BIG_STRAIGHT = lambda dice: 30 if sorted(dice) == [2, 3, 4, 5, 6] else 0
CHOICE = lambda dice: sum(dice)
YACHT = lambda dice: 50 if len(set(dice)) == 1 else 0

def single_digit(dice: list[int], value: int) -> int:
    return Counter(dice)[value] * value

def four_of_a_kind(dice: list[int]) -> int:
    four_dice = [x for x in set(dice) if dice.count(x) >= 4]
    return four_dice[0] * 4 if four_dice else 0

def score(dice: list[int], category: Callable) -> int:
    return category(dice)
