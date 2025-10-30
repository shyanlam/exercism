from unittest import case


def response(hey_bob: str) -> str:
    hey_bob = hey_bob.strip()
    is_question: bool = hey_bob.endswith("?")
    is_yelling: bool = hey_bob.isupper()
    is_silence: bool = hey_bob.isspace() or not hey_bob
    match is_question, is_yelling, is_silence:
        case True, False, _: return "Sure."
        case False, True, _: return "Whoa, chill out!"
        case True, True, _: return "Calm down, I know what I'm doing!"
        case _, _, True: return "Fine. Be that way!"
        case _: return "Whatever."
