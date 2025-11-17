class Luhn:
    def __init__(self, card_num):
        self.card_num = card_num.replace(" ", "")

    @staticmethod
    def double_less_9(ch: str) -> int:
        value = int(ch) * 2
        return value if value <= 9 else value - 9

    def valid(self) -> bool:
        if len(self.card_num) <= 1:
            return False
        if not self.card_num.isdigit():
            return False

        sum1 = sum([Luhn.double_less_9(x) for x in self.card_num[-2::-2]])
        sum2 = sum([int(x) for x in self.card_num[-1::-2]])
        return (sum1 + sum2) % 10 == 0
