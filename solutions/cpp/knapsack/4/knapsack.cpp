#include "knapsack.h"
#include <algorithm>
namespace knapsack {

// TODO: add your solution here
    int maximum_value(int max_weight, const std::vector<Item>& items) {
        if (max_weight == 0 || items.size() == 0)
            return 0;

        std::vector<int> pack_values(max_weight + 1);
        for (auto& item : items) {
            for (int w = max_weight; w >= item.weight; --w) {
                int cur_value = item.value + pack_values[w - item.weight];
                if (pack_values[w] < cur_value)
                    pack_values[w] = cur_value;
            }
        }
        return pack_values[max_weight];
    }

}  // namespace knapsack
