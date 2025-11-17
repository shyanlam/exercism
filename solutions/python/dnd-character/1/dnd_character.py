import random


class Character:
    def __init__(self):
        random.seed(0)
        self.strength = Character.ability()
        self.dexterity = Character.ability()
        self.constitution = Character.ability()
        self.intelligence = Character.ability()
        self.wisdom = Character.ability()
        self.charisma = Character.ability()

    @staticmethod
    def ability() -> int:
        values = [random.randint(1, 6) for _ in range(4)]
        return sum(values) - min(values)

    @property
    def hitpoints(self) -> int:
        return 10 + modifier(self.constitution)


def modifier(value) -> int:
    return (value - 10) // 2


Char = Character()
print(f"{Char.constitution = }")
print(f"{modifier(Char.constitution) = }")
print(f"{Char.hitpoints = }")
