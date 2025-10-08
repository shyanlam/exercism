#include "spiral_matrix.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
namespace spiral_matrix {

// TODO: add your solution here
    std::ostream& operator<<(std::ostream& os, const spiral_matrix_t spiral_matrix) {
        const size_t col_width = std::to_string(spiral_matrix.size() * spiral_matrix.size()).length() + 1;
        for (auto& row : spiral_matrix) {
            for (auto& v : row) {
                os << std::setw(col_width) << v;
            }
            os << std::endl;
        }
        return os;
    }

    enum class movement_t{ left_to_right, top_to_bottom, right_to_left, bottom_to_top };
    std::ostream& operator<<(std::ostream& os, movement_t movement) {
        switch (movement) {
        case movement_t::left_to_right: os << "left to right"; return os;
        case movement_t::top_to_bottom: os << "top to bottom"; return os;
        case movement_t::right_to_left: os << "right to left"; return os;
        case movement_t::bottom_to_top: os << "bottom to top"; return os;
        }
        return os;
    }

    bool fill(spiral_matrix_t& spiral_matrix, int size, int& row, int& col, uint32_t& value, uint32_t last_value, movement_t movement) {
        assert(0 <= row && row < size);
        assert(0 <= col && col < size);
        //if (value <= last_value)
        //    std::cout << movement << std::endl;
        while (value <= last_value) {
            if (spiral_matrix[row][col] == 0) {
                spiral_matrix[row][col] = value++;
                //std::cout << spiral_matrix << std::endl;
            }
            switch (movement) {
            case movement_t::left_to_right:
                if (col < size - 1 && spiral_matrix[row][col + 1] == 0)
                    ++col;
                else
                    return value <= last_value;
                break;
            case movement_t::top_to_bottom:
                if (row < size - 1 && spiral_matrix[row + 1][col] == 0)
                    ++row;
                else
                    return value <= last_value;
                break;
            case movement_t::right_to_left:
                if (col > 0 && spiral_matrix[row][col - 1] == 0)
                    --col;
                else
                    return value <= last_value;
                break;
            case movement_t::bottom_to_top:
                if (row > 0 && spiral_matrix[row - 1][col] == 0)
                    --row;
                else
                    return value <= last_value;
                break;
            }
        }
        return value <= last_value;
    }

    spiral_matrix_t spiral_matrix(int size) {
        spiral_matrix_t spiral_matrix(size, row_t(size, uint32_t{}));
        uint32_t last_value = uint32_t(size) * size;
        int row{ 0 }, col{ 0 };

        for (uint32_t value{ 1 }; value <= last_value;) {
            if (!fill(spiral_matrix, size, row, col, value, last_value, movement_t::left_to_right))
                break;
            row = std::min(row + 1, size - 1);

            if (!fill(spiral_matrix, size, row, col, value, last_value, movement_t::top_to_bottom))
                break;
            col = std::max(col - 1, 0);

            if (!fill(spiral_matrix, size, row, col, value, last_value, movement_t::right_to_left))
                break;
            row = std::max(row - 1, 0);

            if (!fill(spiral_matrix, size, row, col, value, last_value, movement_t::bottom_to_top))
                break;
            col = std::min(col + 1, size - 1);

        }
        
        return spiral_matrix;
    }

}  // namespace spiral_matrix
