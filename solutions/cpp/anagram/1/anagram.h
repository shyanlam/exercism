#pragma once
#include <initializer_list>
#include <string>
#include <map>
#include <unordered_set>
namespace anagram {

// TODO: add your solution here
    class anagram {
    public:
        using letter_count_t = std::map<char, int>;
        using word_list_t = std::initializer_list<std::string>;
        using word_set_t = std::unordered_set <std::string>;

        anagram(const std::string& word);
        word_set_t matches(const word_list_t& words) const;

    private:
        bool is_original_word(const std::string& word) const;
        static letter_count_t get_letter_count(const std::string& word);

    private:
        std::string _original_word;
        letter_count_t _letter_count{};
    };
}  // namespace anagram
