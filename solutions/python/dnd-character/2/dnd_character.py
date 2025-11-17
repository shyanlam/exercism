import random


class Character:
    _ABILITIES = {"strength", "dexterity", "constitution", "intelligence", "wisdom", "charisma"}

    def __init__(self):
        random.seed(0)
        for ability in Character._ABILITIES:
            setattr(self, ability, Character.ability())

    @staticmethod
    def ability() -> int:
        values = [random.randint(1, 6) for _ in range(4)]
        return sum(values) - min(values)

    @property
    def hitpoints(self) -> int:
        return 10 + modifier(self.constitution)


def modifier(value) -> int:
    return (value - 10) // 2
