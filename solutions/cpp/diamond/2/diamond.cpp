#include "diamond.h"
#include <stdexcept>
namespace diamond {

// TODO: add your solution here
    std::vector<std::string> rows(char letter) {
        if (letter < 'A' && 'Z' < letter)
            throw std::domain_error("Invalid character");

        const int diamond_size = (letter - 'A') * 2 + 1;
        std::vector<std::string> result(diamond_size);

        std::string pattern(diamond_size, ' ');
        const int middle_pos{ diamond_size / 2 };
        int left{ middle_pos }, right{ middle_pos };
        int top{ 0 }, bottom{ diamond_size - 1 };
        for (char ch = 'A'; ch <= letter; ++ch) {
            pattern[left] = pattern[right] = ch;
            result[top] = result[bottom] = pattern;
            pattern[left] = pattern[right] = ' ';
            ++top; --bottom;
            --left; ++right;
        }
        return result;
    }

}  // namespace diamond
