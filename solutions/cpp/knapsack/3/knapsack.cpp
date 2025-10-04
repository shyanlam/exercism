#include "knapsack.h"
#include <algorithm>
namespace knapsack {

// TODO: add your solution here
    using row_t = std::vector<int>;
    using table_t = std::vector<row_t>;

    int maximum_value(int max_weight, const std::vector<Item>& items) {
        if (max_weight == 0 || items.size() == 0)
            return 0;

        table_t table{ items.size() + 1, row_t(max_weight + 1, 0)};
        int row{ 1 };
        for (const auto& item : items) {
            for (int w = 0; w <= max_weight; ++w) {
                if (w < item.weight) {
                    table[row][w] = table[row-1][w];
                } else {
                    const int cur_best = table[row - 1][w];
                    const int prev_item = w >= item.weight ? table[row - 1][w - item.weight] : 0;
                    table[row][w] = std::max(item.value + prev_item, cur_best);
                }
            }
            ++row;
        }

        return table.back().back();
    }

}  // namespace knapsack
