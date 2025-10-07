#include "yacht.h"
#include <cassert>
#include <map>
#include <stdexcept>
namespace yacht {

// TODO: add your solution here
    constexpr int LITTLE_STRAIGHT_SCORE = 30;
    constexpr int BIG_STRAIGHT_SCORE = 30;
    constexpr int YACHT_SCORE = 50;

    int score(const std::vector<int>& dice, const std::string& category) {
        std::map<int, int> value_counter{};
        for (auto value : dice) {
            ++value_counter[value];
        }

        const std::map<std::string, int> ONE_TO_SIX{
            {"ones", 1}, {"twos", 2}, {"threes",3}, {"fours", 4}, {"fives", 5}, {"sixes", 6}
        };

        if (auto cat = ONE_TO_SIX.find(category); cat != ONE_TO_SIX.end()) {
            if (auto vc = value_counter.find(cat->second); vc != value_counter.end()) {
                return cat->second * vc->second;
            } 
            return 0;
        } else if (category == "full house") {
            int score{ 0 };
            if (value_counter.size() == 2) {
                for (auto [value, count] : value_counter) {
                    if (count == 2 || count == 3) {
                        score += value * count;
                    }
                }
            }
            return score;

        } else if (category == "four of a kind") {
            if (value_counter.size() <= 2) {
                for (auto [value, count] : value_counter) {
                    if (count >= 4)
                        return value * 4;
                }
            }
            return 0;
        } else if (category.find("straight") != std::string::npos) {
            if (value_counter.size() != 5)
                return 0;
            auto first = *value_counter.begin();
            auto last = *value_counter.rbegin();
            if (first.first == 1 && last.first == 5 && (category.find("little") != std::string::npos))
                return LITTLE_STRAIGHT_SCORE;
            else if (first.first == 2 && last.first == 6 && (category.find("big") != std::string::npos))
                return BIG_STRAIGHT_SCORE;
            else
                return 0;
        } else if (category == "choice") {
            int score{ 0 };
            for (auto [value, count] : value_counter) {
                score += value * count;
            }
            return score;
        } else if (category == "yacht") {
            return value_counter.size() == 1 ? YACHT_SCORE : 0;
        } else {
            throw std::domain_error("invalid category");
        }
    }

}  // namespace yacht
