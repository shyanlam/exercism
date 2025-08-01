#pragma once
#include <initializer_list>
#include <string>
#include <map>
#include <unordered_set>
namespace anagram {

// TODO: add your solution here
    class anagram {
    public:
        using word_list_t = std::initializer_list<std::string>;
        using word_set_t = std::unordered_set <std::string>;

        anagram(const std::string& word);
        word_set_t matches(const word_list_t& words) const;

    private:
        bool is_original_word(const std::string& word) const;
        static std::string tolower_sort(const std::string& word);

    private:
        std::string _original_word;
        std::string _lower_sorted;
    };
}  // namespace anagram
