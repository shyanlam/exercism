#include "dnd_character.h"
#include <array>
#include <cmath>
#include <functional>
#include <numeric>
#include <set>
#include <random>
namespace dnd_character {

// TODO: add your solution here
    int modifier(int constitution) {
        return static_cast<int>(std::floor((constitution - 10) / 2.0f));
    }

    int ability() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> dice(1, 6);
        std::vector<int> rollvalues{ dice(gen), dice(gen), dice(gen), dice(gen) };
        return std::accumulate(rollvalues.begin(), rollvalues.end(), 0) 
            - *std::min_element(rollvalues.begin(), rollvalues.end());
    }
}  // namespace dnd_character
