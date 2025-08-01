#include "anagram.h"
#include <algorithm>
#include <cctype>
namespace anagram {

// TODO: add your solution here
    anagram::anagram(const std::string& word)
        : _original_word(word)
        , _lower_sorted(tolower_sort(word)) {
    }

    anagram::word_set_t anagram::matches(const word_list_t& words) const {
        word_set_t result{};
        for (const auto& word : words) {
            if (!is_original_word(word) && _lower_sorted == tolower_sort(word))
                result.emplace(word);
        }
        return result;
    }

    std::string anagram::tolower_sort(const std::string& word) {
        std::string result(word);
        std::transform(result.begin(), result.end(), result.begin(), std::tolower);
        std::sort(result.begin(), result.end());
        return result;
    }
    bool anagram::is_original_word(const std::string& word) const {
        return std::equal(_original_word.begin(), _original_word.end(),
                          word.begin(), word.end(),
                          [](const char& c1, const char& c2) -> bool {
                            return std::tolower(c1) == std::tolower(c2);
        });
    }
}  // namespace anagram
