import itertools
import re
import operator


def answer(question: str) -> int:
    expression = re.sub(r"\s*What\s+is|\s*\?\s*", "", question)
    expression = expression.replace("plus", " + ").replace("minus", " - ")
    expression = re.sub(r"multiplied\s+by\s+", " * ", expression)
    expression = re.sub(r"divided\s+by\s+", " / ", expression)
    if re.findall(r"[a-zA-Z]", expression):
        raise ValueError("unknown operation")

    if expression.strip() == "":
        raise ValueError("syntax error")
    expression = expression.split()
    group_exp = ["("] + expression[:3] + [")"]
    for n in range(3, len(expression), 2):
        group_exp.insert(0, "(")
        group_exp += expression[n:n+2] + [")"]

    try:
        return eval(" ".join(group_exp))
    except:
        raise ValueError("syntax error")


if __name__ == "__main__":
    questions = [
        # "What is 5?",
        # "What is 1 plus 1?",
        # "What is -123?",
        # "What is -3 plus 7 multiplied by -2?",
        # "What is 2 2 minus 3?",
        "What is?",
        # "What is plus 1 2?",
        # "What is 1 plus?",
        # "What is 52 cubed?",
        # "What is 7 plus multiplied by - 2?",
    ]

    for question in questions:
        print(f"answer({question}) = {answer(question)}")
