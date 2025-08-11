#include "isogram.h"
#include <algorithm>
#include <cctype>
#include <unordered_set>
namespace isogram {

// TODO: add your solution here
    bool is_isogram(const std::string_view& text) {
        std::unordered_set<char> chars;
        for (auto ch : text) {
            if (std::isalpha(ch)) {
                ch = static_cast<char>(std::tolower(ch));
                if (!chars.insert(ch).second)
                    return false;
            }
        }
        return true;
    }

}  // namespace isogram
