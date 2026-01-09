#include "isogram.h"
#include <algorithm>
#include <cctype>
#include <map>
namespace isogram {

// TODO: add your solution here
    bool is_isogram(const std::string_view& text) {
        std::map<char, int> char_count{};
        for (const auto& ch : text) {
            if (std::isalpha(ch)) {
                ++char_count[static_cast<char>(std::tolower(ch))];
            }
        }
        
        return !std::any_of(char_count.cbegin(), char_count.cend(),
                           [](const auto& kvpair) { return kvpair.second > 1; });
    }

}  // namespace isogram
