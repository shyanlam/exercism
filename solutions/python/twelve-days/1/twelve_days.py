from unittest import result

NTH_DAY = ["",
           "first", "second", "third", "fourth", "fifth", "sixth",
           "seventh", "eighth", "ninth", "tenth", "eleventh", "twelfth"
           ]

GIFTS = ["",
         "a Partridge in a Pear Tree.",
         "two Turtle Doves, ",
         "three French Hens, ",
         "four Calling Birds, ",
         "five Gold Rings, ",
         "six Geese-a-Laying, ",
         "seven Swans-a-Swimming, ",
         "eight Maids-a-Milking, ",
         "nine Ladies Dancing, ",
         "ten Lords-a-Leaping, ",
         "eleven Pipers Piping, ",
         "twelve Drummers Drumming, "
         ]


def verse(nth: int) -> list[str]:
    if not 1 <= nth <= 12:
        raise ValueError("nth must be between 1 and 12")

    result: str = f"On the {NTH_DAY[nth]} day of Christmas my true love gave to me: "

    for n in reversed(range(1, nth + 1)):
        if nth > 1 and n == 1:
            result += "and "
        result += GIFTS[n]

    return [result]


def recite(start_verse, end_verse) -> list[str]:
    result: list[str] = []
    for n in range(start_verse, end_verse + 1):
        result.extend(verse(n))
    return result
