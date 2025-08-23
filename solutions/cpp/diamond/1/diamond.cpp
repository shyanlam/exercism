#include "diamond.h"
#include <stdexcept>
namespace diamond {

// TODO: add your solution here
    std::vector<std::string> rows(char ch) {
        if (ch < 'A' && 'Z' < ch)
            throw std::domain_error("Invalid character");

        const int strlen = (ch - 'A') * 2 + 1;
        std::vector<std::string> result(strlen);

        std::string pattern(strlen, ' ');
        const int middle_pos{ strlen / 2 };
        int left{ middle_pos }, right{ middle_pos };
        int top{ 0 }, bottom{ strlen - 1 };
        for (char c = 'A'; c <= ch; ++c) {
            pattern[left] = pattern[right] = c;
            result[top] = result[bottom] = pattern;
            pattern[left] = pattern[right] = ' ';
            ++top; --bottom;
            --left; ++right;
        }
        return result;
    }

}  // namespace diamond
