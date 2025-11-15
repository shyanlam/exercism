from unittest import result

NTH_DAY = ["",
           "first", "second", "third", "fourth", "fifth", "sixth",
           "seventh", "eighth", "ninth", "tenth", "eleventh", "twelfth"
           ]

GIFTS = ["",
         "a Partridge in a Pear Tree.",
         "two Turtle Doves, and ",
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


def recite(start_verse, end_verse) -> list[str]:
    if not (1 <= start_verse <= 12 or 1 <= end_verse <= 12 or start_verse <= end_verse):
        raise ValueError("invalid start_verse or end_verse")

    start = "On the {0} day of Christmas my true love gave to me: "
    return [start.format(NTH_DAY[n]) +
            "".join(GIFTS[n::-1]) for n in range(start_verse, end_verse + 1)]
