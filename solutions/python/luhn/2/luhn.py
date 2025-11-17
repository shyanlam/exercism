class Luhn:
    def __init__(self, card_num):
        self.card_num = card_num.replace(" ", "")

    def valid(self) -> bool:
        if len(self.card_num) <= 1:
            return False
        if not self.card_num.isdigit():
            return False

        num_list = [int(x) for x in self.card_num]
        num_list[-2::-2] = [x * 2 for x in num_list[-2::-2]]
        return sum(map(lambda x: x - 9 if x > 9 else x, num_list)) % 10 == 0
