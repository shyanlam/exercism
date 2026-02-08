from enum import IntEnum, auto
from collections import Counter

SUITS = "CSHD"
# RANKS = ["A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"]
RANKS = {
    "2": 2, "3": 3, "4": 4, "5": 5, "6": 6, "7": 7, "8": 8, "9": 9, "10": 10,
    "J": 11, "Q": 12, "K": 13,
    "A": 14
}

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


def poker_value(hand: str) -> tuple[CATEGORY, list[int]]:
    cards = [(card[0:-1], card[-1]) for card in hand.split()]
    ranks, suits = zip(*cards)
    suits_count = Counter(suits).most_common()
    ranks_count = Counter([RANKS[rank] for rank in ranks]).most_common()

    if len(ranks_count) == 2:
        # 4 of a kind or full house
        if ranks_count[0][1] == 4:
            return CATEGORY.FOUR_OF_A_KIND, [ranks_count[0][0], ranks_count[1][0]]
        if ranks_count[0][1] == 3:
            return CATEGORY.FULL_HOUSE, [ranks_count[0][0], ranks_count[1][0]]
    if len(ranks_count) == 3:
        # 3 of a kind or two pair
        if ranks_count[0][1] == 3:
            kicker = sorted([r for r, _ in ranks_count[1:]], reverse=True)
            return CATEGORY.THREE_OF_A_KIND, [ranks_count[0][0], *kicker]
        if ranks_count[0][1] == 2:
            assert ranks_count[1][1] == 2
            pairs = sorted([r for r, _ in ranks_count[0:2]], reverse=True)
            return CATEGORY.TWO_PAIR, [*pairs, ranks_count[2][0]]
    if len(ranks_count) == 4:
        # one pair
        kicker = sorted([r for r, _ in ranks_count[1:]], reverse=True)
        return CATEGORY.ONE_PAIR, [ranks_count[0][0], *kicker]
    else:
        assert len(ranks_count) == 5
        # straight, flush or no pair
        suits_count = Counter(suits).most_common()
        if set(ranks) == {'A', '2', '3', '4', '5'}:
            return CATEGORY.STRAIGHT_FLUSH if len(suits_count) == 1 else CATEGORY.STRAIGHT, [5]
        rank_values = sorted([r for r, _ in ranks_count])
        if is_consecutive(rank_values):
            return CATEGORY.STRAIGHT_FLUSH if len(suits_count) == 1 else CATEGORY.STRAIGHT, [max(rank_values)]
        else:
            return CATEGORY.FLUSH if len(suits_count) == 1 else CATEGORY.NO_PAIR, rank_values[::-1]


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
        hand_value = poker_value(hand)
        if len(best_so_far) == 0:
            best_so_far = [hand_value]
            best_hand_so_far = [hand]
        else:
            if (cmp := compare_poker_value(hand_value, best_so_far[0])) == 1:
                best_so_far = [hand_value]
                best_hand_so_far = [hand]
            elif cmp == 0:
                best_so_far.append(hand_value)
                best_hand_so_far.append(hand)
    return best_hand_so_far
