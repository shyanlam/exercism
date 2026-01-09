import re
import string

from attr import attributes


class PhoneNumber:
    def __init__(self, number: str):
        self.number = PhoneNumber.validate_and_cleanup(number)

    @staticmethod
    def validate_and_cleanup(number: str) -> str:
        re_valid_punctuation = re.compile(r"[+().\-\s]")
        number = re_valid_punctuation.sub("", number)

        if len(number) < 10:
            raise ValueError("must not be fewer than 10 digits")
        if len(number) > 11:
            raise ValueError("must not be greater than 11 digits")
        if len(number) == 11:
            if number[0] != "1":
                raise ValueError("11 digits must start with 1")
            number = number[1:]

        if any(map(lambda x: x in string.punctuation, number)):
            raise ValueError("punctuations not permitted")

        if re.search(r"[a-zA-Z]", number):
            raise ValueError("letters not permitted")

        number = re.sub(r"\D", "", number)

        if number[3] == "1":
            raise ValueError("exchange code cannot start with one")
        if number[3] == "0":
            raise ValueError("exchange code cannot start with zero")
        if number[0] == "0":
            raise ValueError("area code cannot start with zero")
        if number[0] == "1":
            raise ValueError("area code cannot start with one")

        return number

    @property
    def area_code(self) -> str:
        return self.number[0:3]

    def pretty(self):
        return f"({self.area_code})-{self.number[3:6]}-{self.number[6:]}"
