#include "pascals_triangle.h"
#include <cstddef>
namespace pascals_triangle {

// TODO: add your solution here
    std::vector<int> next_row(std::vector<int>& row_value) {
        std::vector<int> next(row_value.size() + 1, 1);
        for (size_t n = 0; n < row_value.size(); ++n) {
            if (n + 1 < row_value.size()) {
                next[n + 1] = row_value[n] + row_value[n + 1];
            }
        }
        return next;
    }

    std::vector<std::vector<int>> generate_rows(int row) {
        if (row == 0)
            return {};

        std::vector<std::vector<int>> result{ {1} };
        for (int n = 1; n < row; ++n) {
            result.emplace_back(next_row(result[n-1]));
        }
        return result;
    }

}  // namespace pascals_triangle
