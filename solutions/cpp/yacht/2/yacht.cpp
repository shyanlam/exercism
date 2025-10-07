#include "yacht.h"
#include <algorithm>
#include <cassert>
#include <map>
#include <stdexcept>
namespace yacht {

// TODO: add your solution here
    constexpr int LITTLE_STRAIGHT_SCORE = 30;
    constexpr int BIG_STRAIGHT_SCORE = 30;
    constexpr int YACHT_SCORE = 50;

    int score(std::vector<int> dice, const std::string& category) {
        std::map<int, int> value_count{};
        int sum{ 0 };
        for (auto value : dice) {
            ++value_count[value];
            sum += value;
        }
        std::sort(dice.begin(), dice.end());

        if (category == "ones") {
            return 1 * value_count[1];
        } else if (category == "twos") {
            return 2 * value_count[2];
        } else if (category == "threes") {
            return 3 * value_count[3];
        } else if (category == "fours") {
            return 4 * value_count[4];
        } else if (category == "fives") {
            return 5 * value_count[5];
        } else if (category == "sixes") {
            return 6 * value_count[6];
        } else if (category == "full house") {
            if (value_count.size() == 2) {
                if (auto count = value_count.begin()->second; count == 2 || count == 3) {
                    return sum;
                }
            }
            return 0;
        } else if (category == "four of a kind") {
            if (value_count.size() <= 2) {
                for (auto [value, count] : value_count) {
                    if (count >= 4)
                        return value * 4;
                }
            }
            return 0;
        } else if (category == "little straight") {
            return dice == std::vector<int>{1, 2, 3, 4, 5} ? LITTLE_STRAIGHT_SCORE : 0;
        } else if (category == "big straight") {
            return dice == std::vector<int>{2, 3, 4, 5, 6} ? BIG_STRAIGHT_SCORE : 0;
        } else if (category == "choice") {
            return sum;
        } else if (category == "yacht") {
            return value_count.size() == 1 ? YACHT_SCORE : 0;
        } else {
            throw std::domain_error("invalid category");
        }
    }

}  // namespace yacht
