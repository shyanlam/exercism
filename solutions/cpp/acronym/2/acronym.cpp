#include "acronym.h"
#include <cassert>
#include <cctype>
#include <sstream>
namespace acronym {

// TODO: add your solution here
    std::string acronym(const std::string& text) {
        std::stringstream ssCleaned;
        for (auto ch : text) {
            if (std::isalpha(ch))
                ssCleaned << ch;
            else if (ch == '-' || std::isspace(ch))
                ssCleaned << ' ';
        }

        std::stringstream ssResult;
        for (std::string word; ssCleaned >> word;) {
            ssResult << static_cast<char>(std::toupper(word[0]));
        }
        return ssResult.str();
    }

}  // namespace acronym
