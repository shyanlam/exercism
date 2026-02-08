from enum import IntEnum, auto
from collections import Counter

SUITS = "CSHD"
RANKS = ["", "", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"]
class CATEGORY(IntEnum):
    NO_PAIR = auto()
    ONE_PAIR = auto()
    TWO_PAIR = auto()
    THREE_OF_A_KIND = auto()
    STRAIGHT = auto()
    FLUSH = auto()
    FULL_HOUSE = auto()
    FOUR_OF_A_KIND = auto()
    STRAIGHT_FLUSH = auto()


def is_consecutive(int_list: list[int]) -> bool:
    return all([v-n == int_list[0] for n, v in enumerate(int_list)])


def hand_value(hand: str) -> tuple[CATEGORY, list[int]]:
    cards = [(card[:-1], card[-1]) for card in hand.split()]
    ranks, suits = zip(*cards)
    ranks_value = [RANKS.index(r) for r in ranks]
    rank_count = Counter(ranks_value).most_common()
    match [count for _, count in rank_count]:
        case [4, 1]:
            return CATEGORY.FOUR_OF_A_KIND, [r for r, _ in rank_count]
        case [3, 2]:
            return CATEGORY.FULL_HOUSE, [r for r, _ in rank_count]
        case [3, 1, 1]:
            kicker = sorted([r for r, _ in rank_count[1:]], reverse=True)
            return CATEGORY.THREE_OF_A_KIND, [rank_count[0][0], *kicker]
        case [2, 2, 1]:
            pairs = sorted([r for r, _ in rank_count[0:2]], reverse=True)
            return CATEGORY.TWO_PAIR, [*pairs, rank_count[2][0]]
        case [2, 1, 1, 1]:
            kicker = sorted([r for r, _ in rank_count[1:]], reverse=True)
            return CATEGORY.ONE_PAIR, [rank_count[0][0], *kicker]
        case [1, 1, 1, 1, 1]:
            flush = len(Counter(suits).most_common()) == 1
            if set(ranks) == {'A', '2', '3', '4', '5'}:
                return CATEGORY.STRAIGHT_FLUSH if flush else CATEGORY.STRAIGHT, [5]
            if is_consecutive(sorted(ranks_value)):
                return CATEGORY.STRAIGHT_FLUSH if flush else CATEGORY.STRAIGHT, [max(ranks_value)]
            else:
                return CATEGORY.FLUSH if flush else CATEGORY.NO_PAIR, sorted(ranks_value, reverse=True)


def compare_poker_value(hand1: tuple[CATEGORY, list[int]], hand2: tuple[CATEGORY, list[int]]) -> int:
    # return 1 if hand1 > hand2
    #        0 if hand1 == hand2
    #       -1 if hand1 < hand2
    if hand1[0] > hand2[0]:
        return 1
    elif hand1[0] < hand2[0]:
        return -1
    else:
        assert len(hand1[1]) == len(hand2[1])
        for v1, v2 in zip(hand1[1], hand2[1]):
            if v1 > v2:
                return 1
            elif v1 < v2:
                return -1
        return 0


def best_hands(hands: list[str]) -> list[str]:
    global SUITS, RANKS
    best_so_far = []
    best_hand_so_far = []
    for hand in hands:
        value = hand_value(hand)
        if len(best_so_far) == 0:
            best_so_far = [value]
            best_hand_so_far = [hand]
        else:
            if (cmp := compare_poker_value(value, best_so_far[0])) == 1:
                best_so_far = [value]
                best_hand_so_far = [hand]
            elif cmp == 0:
                best_so_far.append(value)
                best_hand_so_far.append(hand)
    return best_hand_so_far


# def do_best_hands(hands: list[str]):
#     result = best_hands(hands)
#     print(f"best_hands({hands}) = {result}")
#
# do_best_hands(["KC AH AS AD AC", "10C JC QC KC AC"])
# do_best_hands(["3H 6H 7H 8H 5H", "4S 5H 4C 5D 4H"])