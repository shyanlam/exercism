import random
from string import ascii_uppercase as LETTERS
from string import digits as DIGITS

class Robot:
    random.seed()
    USED_NAMES: set[str] = set()

    def __init__(self):
        self.name = Robot.new_name()

    def reset(self):
        self.name = Robot.new_name()

    @staticmethod
    def new_name() -> str:
        while True:
            name = "".join(random.choices(LETTERS, k=2) + random.choices(DIGITS, k=3))
            if name not in Robot.USED_NAMES:
                Robot.USED_NAMES.add(name)
                return name
