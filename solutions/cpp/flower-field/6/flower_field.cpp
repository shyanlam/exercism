#include "flower_field.h"
#include <cctype>
#include <cassert>
namespace flower_field {

// TODO: add your solution here
    constexpr char FLOWER = '*';

    void increment_cell(std::vector<std::string>& board, const int row, const int col) {
        if (0 <= row && static_cast<size_t>(row) < board.size() &&
            0 <= col && static_cast<size_t>(col) < board[row].size()) {
            if (board[row][col] == ' ')
                board[row][col] = '1';
            else if (std::isdigit(board[row][col]))
                board[row][col] += 1;
        }
    }

    std::vector<std::string> annotate(std::vector<std::string> board) {
        if (board.empty())
            return board;

        const int row_count = board.size();
        const int col_count = board[0].length();

        for (int row = 0; row < row_count; ++row) {
            std::string& board_row = board[row];
            for (int col = 0; col < col_count; ++col) {
                if (board[row][col] != FLOWER)
                    continue;

                increment_cell(board, row - 1, col - 1);
                increment_cell(board, row - 1, col);
                increment_cell(board, row - 1, col + 1);

                increment_cell(board, row, col - 1);
                increment_cell(board, row, col + 1);

                increment_cell(board, row + 1, col - 1);
                increment_cell(board, row + 1, col);
                increment_cell(board, row + 1, col + 1);
            }
        }
        return board;
    }

}  // namespace flower_field
