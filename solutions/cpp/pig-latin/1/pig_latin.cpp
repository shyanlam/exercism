#include "pig_latin.h"
#include <cctype>
#include <regex>
#include <sstream>
namespace pig_latin {

// TODO: add your solution here
#define PP_OR              "|"
#define PP_BOL             "^"
#define PP_VOWEL           "aeiou"
#define PP_IN(x)           "[" x "]"
#define PP_NOT_IN(x)       "[^" x "]"
#define PP_ANY_VOWEL       PP_IN(PP_VOWEL)
#define PP_ANY_CONSONANT   PP_NOT_IN(PP_VOWEL)
#define PP_ONE_OR_MORE(x)  x "+"
#define PP_GROUP(x)        "(" x ")"
#define PP_ZERO_OR_MORE(x) x "*"

    #define RULE_1 PP_BOL PP_GROUP(PP_ANY_VOWEL PP_OR "xr" PP_OR "yt") PP_GROUP(".*")
    #define RULE_2 PP_BOL PP_GROUP(PP_ONE_OR_MORE(PP_ANY_CONSONANT)) PP_GROUP(".*")
    #define RULE_3 PP_BOL PP_GROUP(PP_ZERO_OR_MORE(PP_ANY_CONSONANT) "qu") PP_GROUP(".*")
    #define RULE_4 PP_BOL PP_GROUP(PP_ONE_OR_MORE(PP_ANY_CONSONANT)) PP_GROUP("y.*")

    const std::vector<std::regex> rules{
        std::regex(RULE_1),
        std::regex(RULE_3),
        std::regex(RULE_4),
        std::regex(RULE_2),
    };

    std::string translate_word(const std::string& word) {
        for (size_t n = 0; n < rules.size(); ++n) {
            auto begin = std::sregex_iterator(word.begin(), word.end(), rules[n]);
            auto end = std::sregex_iterator{};
            for (auto it = begin; it != end; ++it) {
                std::smatch m = *it;
                if (n == 0) { // rule 1
                    return m.str() + "ay";
                } else {
                    return m[2].str() + m[1].str() + "ay";
                }
            }
        }
        return "";
    }

    std::string translate(const std::string& english) {
        std::istringstream ss(english);
        std::string word;
        std::string result;
        while (ss >> word) {
            if (!result.empty()) result += " ";
            result += translate_word(word);
        }
        return result;
    }

}  // namespace pig_latin
