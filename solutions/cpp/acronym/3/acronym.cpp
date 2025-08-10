#include "acronym.h"
#include <cassert>
#include <cctype>
#include <sstream>
namespace acronym {

// TODO: add your solution here
    std::string acronym(const std::string& text) {
        static auto same_as_space = [](const char c) -> bool {
            return std::isspace(c) || c == '-';
        };
        static auto ignore = [](const char c) -> bool {
            return std::ispunct(c) && c != '-';
        };
        std::stringstream ssResult;
        char prev = ' ';
        for (auto ch : text) {
            if (ignore(ch)) {
                continue;
            } else if (std::isalpha(ch) && same_as_space(prev)) {
                ssResult << static_cast<char>(std::toupper(ch));
            }
            prev = ch;
        }

        return ssResult.str();
    }

}  // namespace acronym
