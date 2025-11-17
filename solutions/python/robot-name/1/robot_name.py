import random
import string


class Robot:
    def __init__(self):
        self.name = Robot.new_name()

    def reset(self):
        self.name = Robot.new_name()

    @staticmethod
    def new_name() -> str:
        random.seed()
        return "".join(random.choices(string.ascii_uppercase, k=2) +
                       random.choices(string.digits, k=3))
