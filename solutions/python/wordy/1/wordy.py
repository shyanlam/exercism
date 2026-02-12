import itertools
import re
import operator
from typing import Callable


def parse_question(question: str) -> tuple[bool, str]:
    _PREFIX = "What is "
    _SUFFIX = "?"
    if question.startswith(_PREFIX) and question.endswith(_SUFFIX):
        return True, question.removeprefix(_PREFIX).removesuffix(_SUFFIX)
    else:
        return False, ""


def try_extract_value(expression: str) -> tuple[int, str]:
    try:
        value, *rest = expression.split(maxsplit=1)
        return int(value), "".join(rest)
    except:
        raise ValueError("syntax error")


OPERATIONS = {
    "plus": operator.add,
    "minus": operator.sub,
    "multiplied": operator.mul,
    "divided": operator.floordiv,
}


def try_extract_operation(expression: str) -> tuple[Callable[[int, int], int], str]:
    global OPERATIONS
    operation, *rest = expression.split(maxsplit=1)
    if (op := OPERATIONS.get(operation, None)) is None:
        if re.match(r"\d+", operation):
            raise ValueError("syntax error")
        else:
            raise ValueError("unknown operation")

    if op == operator.mul or op == operator.floordiv:
        _by, *rest = "".join(rest).split(maxsplit=1)
        if _by != "by":
            raise ValueError("syntax error")
    return op, "".join(rest)


def answer(question: str) -> int:
    valid, expression = parse_question(question)
    if not valid:
        raise ValueError("syntax error")

    if len(expression) == 0:
        raise ValueError("syntax error")

    result, expression = try_extract_value(expression)
    while expression != "":
        op, expression = try_extract_operation(expression)
        value, expression = try_extract_value(expression)
        result = op(result, value)

    return result
