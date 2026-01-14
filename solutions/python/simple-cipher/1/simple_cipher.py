import secrets
import string
import operator

class Cipher:
    DEFAULT_KEY_COUNT = 100
    KEYS = string.ascii_lowercase

    def __init__(self, key: str | None =None):
        if key is None:
            key = "".join([secrets.choice(Cipher.KEYS) for n in range(Cipher.DEFAULT_KEY_COUNT)])
        self.key = key

    def _xcode(self, text_or_code: str, operation) -> str:
        result = ""
        key_index = 0
        for char in text_or_code:
            distance = Cipher.KEYS.index(self.key[key_index])
            index = operation(Cipher.KEYS.index(char), distance) % len(self.KEYS)
            result += Cipher.KEYS[index]
            key_index = (key_index + 1) % len(self.key)
        return result


    def encode(self, text: str) -> str:
        return self._xcode(text, operator.__add__)

    def decode(self, code: str) -> str:
        return self._xcode(code, operator.__sub__)

