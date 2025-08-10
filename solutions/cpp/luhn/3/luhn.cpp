#include "luhn.h"
#include <algorithm>
#include <array>
#include <map>
#include <cctype>
namespace luhn {

// TODO: add your solution here
    static const std::map<char, std::array<int, 2>> DIGIT_TO_VALUE{
        {'0', {0, 0}},
        {'1', {2, 1}},
        {'2', {4, 2}},
        {'3', {6, 3}},
        {'4', {8, 4}},
        {'5', {1, 5}},
        {'6', {3, 6}},
        {'7', {5, 7}},
        {'8', {7, 8}},
        {'9', {9, 9}},
    };

    bool valid(std::string numbers) {
        numbers.erase(std::remove_if(numbers.begin(), numbers.end(),
                      [](const char c) -> bool {return std::isspace(c); }), numbers.end());

        int sum{ 0 };
        int digit_count{ 0 };
        for (auto crit = numbers.rbegin(); crit != numbers.rend(); ++crit) {
            const auto& ch = *crit;
            if (!std::isdigit(ch))
                return false;

            ++digit_count;
            const auto& values = DIGIT_TO_VALUE.at(ch);
            sum += values[digit_count % 2];
        }
        return digit_count > 1 && sum % 10 == 0;
    }

}  // namespace luhn
