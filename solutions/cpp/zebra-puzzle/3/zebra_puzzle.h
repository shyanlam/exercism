#pragma once
#include <algorithm>
#include <cassert>
#include <set>
#include <string>
#include <vector>

namespace zebra_puzzle {
    struct Solution {
        std::string drinksWater;
        std::string ownsZebra;
    };

    Solution solve();
}  // namespace zebra_puzzle
