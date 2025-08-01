#include "anagram.h"
#include <algorithm>
#include <cctype>
namespace anagram {

// TODO: add your solution here
    anagram::anagram(const std::string& word)
        : _original_word(word)
        , _letter_count(get_letter_count(word)) {
    }

    anagram::letter_count_t anagram::get_letter_count(const std::string& word) {
        letter_count_t letter_count{};
        for (const auto& ch : word) {
            ++letter_count[std::tolower(ch)];
        }
        return letter_count;
    }

    anagram::word_set_t anagram::matches(const word_list_t& words) const {
        word_set_t result{};
        for (const auto& word : words) {
            if (!is_original_word(word) && get_letter_count(word) == _letter_count)
                result.emplace(word);
        }
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
