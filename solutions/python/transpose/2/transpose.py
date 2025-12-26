import itertools
from itertools import zip_longest


def transpose(text: str) -> str:
    str_list = text.split("\n")
    result = list(itertools.zip_longest(*str_list, fillvalue=" "))
    result = ["".join(line) for line in result]
    result = list(map(str.rstrip, result))
    return "\n".join(result)

# do_transpose("AB\nDEF\nGH")
def do_transpose(text: str):
    print(f"transpose({repr(text)}) = {repr(transpose(text))}")

# do_transpose("ABC\nDE")
# do_transpose("AB\nDEF")
# do_transpose("AB\nFG\n1234\nUVWXY\nKLMN")
# do_transpose("The fourth line.\nThe fifth line.")
# do_transpose("The first line.\nThe second line.")
# do_transpose("The longest line.\nA long line.\nA longer line.\nA line.")
#"TAAA\nh   \nelll\n ooi\nlnnn\nogge\nn e.\nglr\nei \nsnl\ntei\n .n\nl e\ni .\nn\ne\n."