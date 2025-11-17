import random
import itertools
from typing import Iterator
from string import ascii_uppercase as LETTERS
from string import digits as DIGITS

class Robot:
    NAMES: Iterator[str]

    def __init__(self):
        letters = [a + b for a, b in itertools.product(LETTERS, repeat = 2)]
        digits = [str(n).zfill(3) for n in range(1000)]
        names = list(letter + digit for letter, digit in itertools.product(letters, digits))
        random.seed()
        random.shuffle(names)
        Robot.NAMES = iter(names)
        self.name = next(Robot.NAMES)

    def reset(self):
        self.name = next(Robot.NAMES)
