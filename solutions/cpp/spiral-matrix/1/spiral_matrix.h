#pragma once
#include <cstdint>
#include <vector>
namespace spiral_matrix {

// TODO: add your solution here
    using row_t = std::vector<uint32_t>;
    using spiral_matrix_t = std::vector<row_t>;
    spiral_matrix_t spiral_matrix(int);
}  // namespace spiral_matrix
