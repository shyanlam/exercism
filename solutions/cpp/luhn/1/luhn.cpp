#include "luhn.h"
#include <algorithm>
#include <map>
#include <cctype>
namespace luhn {

// TODO: add your solution here
    static const std::map<char, std::pair<int, int>> DIGIT_TO_VALUE{
        {'0', {0, 0}},
        {'1', {1, 2}},
        {'2', {2, 4}},
        {'3', {3, 6}},
        {'4', {4, 8}},
        {'5', {5, 1}},
        {'6', {6, 3}},
        {'7', {7, 5}},
        {'8', {8, 7}},
        {'9', {9, 9}},
    };

    bool valid(std::string numbers) {
        numbers.erase(std::remove_if(numbers.begin(), numbers.end(), std::isspace), numbers.end());

        if (numbers.length() <= 1)
            return false;

        int sum{ 0 };
        bool make_double{ false };
        for (auto crit = numbers.rbegin(); crit != numbers.rend(); ++crit) {
            if (!std::isdigit(*crit))
                return false;

            const auto& values = DIGIT_TO_VALUE.at(*crit);
            if (make_double) {
                sum += values.second;
            } else {
                sum += values.first;
            }
            make_double = !make_double;
        }
        return sum % 10 == 0;
    }

}  // namespace luhn
