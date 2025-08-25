#include "flower_field.h"
#include <cassert>
namespace flower_field {

// TODO: add your solution here
    int flower(const std::vector<std::string>& board, const int row, const int col) {
        constexpr char FLOWER = '*';

        if (0 <= row && row < board.size() &&
            0 <= col && static_cast<size_t>(col) < board[row].length()) {
            return board[row][col] == FLOWER ? 1 : 0;
        }
        return 0;
    }

    int get_adjacent_flowers(const std::vector<std::string>& board, const int row, const int col) {
        // (r-1, c-1) | (r-1, c) | (r-1, c+1)
        // -----------+----------+-------------
        //   (r, c-1) |  (r, c)  | (r, c+1)
        // -----------+----------+-------------
        // (r+1, c-1) | (r+1, c) | (r+1, c+1)
        return flower(board, row - 1, col - 1) + flower(board, row - 1, col) + flower(board, row - 1, col + 1)
            + flower(board, row, col - 1) + flower(board, row, col + 1)
            + flower(board, row + 1, col - 1) + flower(board, row + 1, col) + flower(board, row + 1, col + 1);

    }

    std::vector<std::string> annotate(std::vector<std::string> board) {
        if (board.empty())
            return board;

        const int row_count = board.size();
        const int col_count = board[0].length();

        for (int row = 0; row < row_count; ++row) {
            std::string& board_row = board[row];
            assert(board_row.length() == static_cast<size_t>(col_count));
            for (int col = 0; col < col_count; ++col) {
                if (!flower(board, row, col)) {
                    if (const int adjacent_flowers = get_adjacent_flowers(board, row, col); adjacent_flowers > 0) {
                        assert(adjacent_flowers < 9);
                        board[row][col] = std::to_string(adjacent_flowers)[0];
                    }
                }
            }
        }
        return board;
    }

}  // namespace flower_field
