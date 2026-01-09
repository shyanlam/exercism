#include "pig_latin.h"
#include <algorithm>
#include <cctype>
#include <regex>
namespace pig_latin {

// TODO: add your solution here
    std::string translate(const std::string& english) {
        static std::regex rule1("^(?:(?:[aeiou]|xr|yt)[a-z]*)");
        static std::regex rule2("^([^aeiou\\s]+)([a-z]*)");
        static std::regex rule3("^([^[aeiou\\s]*qu)([a-z]*)");
        static std::regex rule4("^([^aeiouy\\s]+)(y[a-z]*)");
        std::string result{};

        auto w_start = english.begin();
        while (w_start != english.end()) {
            w_start = std::find_if_not(w_start, english.end(), [](char c) {return std::isspace(c); });
            auto w_end = std::find_if(w_start, english.end(), [](char c) {return ::isspace(c); });
            std::string word(w_start, w_end);
            std::smatch m;
            if (std::regex_match(w_start, w_end, m, rule1)) {
                if (!result.empty()) result += " ";
                result += word + "ay";
            } else {
                if (std::regex_match(w_start, w_end, m, rule3) ||
                    std::regex_match(w_start, w_end, m, rule4) ||
                    std::regex_match(w_start, w_end, m, rule2)) {
                    if (!result.empty()) result += " ";
                    result += m[2].str() + m[1].str() + "ay";
                }
            }

            w_start = w_end;
        }
        return result;
    }
}  // namespace pig_latin
