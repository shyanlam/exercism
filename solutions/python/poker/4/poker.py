from enum import IntEnum, auto
from collections import Counter

class PokerHand:
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

    @staticmethod
    def _is_consecutive(rank_value: list[int]) -> bool:
        rank_value = sorted(rank_value)
        return all([v - n == rank_value[0] for n, v in enumerate(rank_value)])


    def __init__(self, hand: str):
        self.cards = [(card[:-1], card[-1]) for card in hand.split()]
        self.ranks, self.suits = zip(*self.cards)
        self.values = [PokerHand.RANKS.index(r) for r in self.ranks]
        rank_count = Counter(self.ranks).most_common()
        match [count for _, count in rank_count]:
            case [4, 1]: # four of a kind
                self.category = self.CATEGORY.FOUR_OF_A_KIND
                self.values = [r for r, _ in rank_count]
            case [3, 2]:
                self.category = self.CATEGORY.FULL_HOUSE
                self.values = [r for r, _ in rank_count]
            case [3, 1, 1]:
                self.category = self.CATEGORY.THREE_OF_A_KIND
                self.values = [rank_count[0][0], *sorted([r for r, _ in rank_count[1:]], reverse=True)]
            case [2, 2, 1]:
                self.category = self.CATEGORY.TWO_PAIR
                # pairs = sorted([r for r, _ in rank_count[0:2]], reverse=True)
                self.values = [*sorted([r for r, _ in rank_count[0:2]], reverse=True), rank_count[2][0]]
            case [2, 1, 1, 1]:
                # kicker = sorted([r for r, _ in rank_count[1:]], reverse=True)
                self.category = self.CATEGORY.ONE_PAIR
                self.values = [rank_count[0][0], *sorted([r for r, _ in rank_count[1:]], reverse=True)]
            case [1, 1, 1, 1, 1]:
                flush = len(Counter(self.suits).most_common()) == 1
                if set(self.ranks) == {'A', '2', '3', '4', '5'}:
                    self.category = self.CATEGORY.STRAIGHT_FLUSH if flush else self.CATEGORY.STRAIGHT
                    self.values = [5]
                else:
                    values = sorted([PokerHand.RANKS.index(r) for r in self.ranks], reverse=True)
                    if PokerHand._is_consecutive(sorted(values)):
                        self.category = self.CATEGORY.STRAIGHT_FLUSH if flush else self.CATEGORY.STRAIGHT
                        self.values = [max(values)]
                    else:
                        self.category = self.CATEGORY.FLUSH if flush else self.CATEGORY.NO_PAIR
                        self.values = values


    def cmp(self, other: PokerHand) -> int:
        if self.category > other.category:
            return 1
        elif self.category < other.category:
            return -1
        else:
            assert len(self.values) == len(other.values)
            for v1, v2 in zip(self.values, other.values):
                if v1 > v2:
                    return 1
                elif v1 < v2:
                    return -1
            return 0


def best_hands(hands: list[str]) -> list[str]:
    # global SUITS, RANKS
    best_so_far = []
    best_hand_so_far = []
    for hand in hands:
        ph = PokerHand(hand)
        # value = hand_value(hand)
        if len(best_so_far) == 0:
            best_so_far = [ph]
            best_hand_so_far = [hand]
        else:
            if (cmp := ph.cmp(best_so_far[0])) == 1:
                best_so_far = [ph]
                best_hand_so_far = [hand]
            elif cmp == 0:
                best_so_far.append(ph)
                best_hand_so_far.append(hand)
    return best_hand_so_far
