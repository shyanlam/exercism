import itertools
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
        for ch, ky in zip(text_or_code, itertools.cycle(self.key)):
            distance = Cipher.KEYS.index(ky)
            result  += Cipher.KEYS[operation(Cipher.KEYS.index(ch), distance) % len(self.KEYS)]
        return result

    def encode(self, text: str) -> str:
        return self._xcode(text, operator.__add__)

    def decode(self, code: str) -> str:
        return self._xcode(code, operator.__sub__)
