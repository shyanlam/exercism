#include "scrabble_score.h"
#include <cassert>
#include <cctype>
#include <map>
namespace scrabble_score {

// TODO: add your solution here

    int get_letter_score(char ch) {
        switch (std::toupper(ch)) {
        case 'A': case 'E': case 'I': case 'O': case 'U':
        case 'L': case 'N': case 'R': case 'S': case 'T':
            return 1;

        case 'D': case 'G':
            return 2;

        case 'B': case 'C': case 'M': case 'P':
            return 3;

        case 'F': case 'H': case 'V': case 'W': case 'Y':
            return 4;

        case 'K':
            return 5;

        case 'J': case 'X':
            return 8;

        case 'Q': case 'Z':
            return 10;
        }
        assert(false);
        return -1;
    }
    int score(const std::string_view& text) {
        int total_score{ 0 };
        for (auto ch : text) {
            total_score += get_letter_score(ch);
        }
        return total_score;
    }

}  // namespace scrabble_score
