#include "acronym.h"
#include <cassert>
#include <cctype>
#include <algorithm>
#include <regex>
#include <sstream>
namespace acronym {

// TODO: add your solution here
    std::string acronym(std::string text) {
        static std::regex rx{ R"(\b([a-zA-Z]))"};

        text.erase(std::remove_if(text.begin(), text.end(), [](const char ch) -> bool {
            return ch != '-' && std::ispunct(ch);}), text.end());

        auto begin = std::sregex_iterator(text.begin(), text.end(), rx);
        auto end = std::sregex_iterator{};
        std::stringstream ss;
        for (auto c = begin; c != end; ++c) {
            const auto& match = *c;
            assert(match.str().length() == 1);
            ss << static_cast<char>(std::toupper(match.str()[0]));
        }
        return ss.str();
    }

}  // namespace acronym
