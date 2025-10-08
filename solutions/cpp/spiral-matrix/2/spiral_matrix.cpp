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

    spiral_matrix_t spiral_matrix(int size) {
        spiral_matrix_t spiral_matrix(size, row_t(size, uint32_t{}));
        uint32_t value{ 1 };
        uint32_t last_value = uint32_t(size) * size;
        int row_start{ 0 }, row_end{ size - 1 }, col_start{ 0 }, col_end{ size - 1 };

        while (value <= last_value && row_start <= row_end && col_start <= col_end) {
            // top (left to right)
            for (auto col = col_start; col <= col_end; ++col) {
                assert(spiral_matrix[row_start][col] == 0);
                spiral_matrix[row_start][col] = value++;
                //std::cout << spiral_matrix << std::endl;
            }
            ++row_start;

            // right (top to bottom)
            for (auto row = row_start; row <= row_end; ++row) {
                assert(spiral_matrix[row][col_end] == 0);
                spiral_matrix[row][col_end] = value++;
                //std::cout << spiral_matrix << std::endl;
            }
            --col_end;

            // bottom (right to left)
            for (auto col = col_end; col >= col_start; --col) {
                assert(spiral_matrix[row_end][col] == 0);
                spiral_matrix[row_end][col] = value++;
                //std::cout << spiral_matrix << std::endl;
            }
            --row_end;

            // left (bottom to top)
            for (auto row = row_end; row >= row_start; --row) {
                assert(spiral_matrix[row][col_start] == 0);
                spiral_matrix[row][col_start] = value++;
                //std::cout << spiral_matrix << std::endl;
            }
            ++col_start;
        }
        return spiral_matrix;
    }

}  // namespace spiral_matrix
