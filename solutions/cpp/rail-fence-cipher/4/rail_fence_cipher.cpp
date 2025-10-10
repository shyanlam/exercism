#include "rail_fence_cipher.h"
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
namespace rail_fence_cipher {
    constexpr auto UNUSED = '.';
    constexpr auto PLACE_HOLDER = '?';
    using crypto_board_t = std::vector<std::string>;

    std::ostream& operator<<(std::ostream& os, const crypto_board_t& crypto_board) {
        for (auto& row : crypto_board) {
            for (auto& ch : row) {
                os << std::setw(2) << ch;
            }
            os << std::endl;
        }
        os << std::endl;
        return os;
    }

    size_t row_from_col(size_t col, int num_rails) {
        auto p = 2 * (num_rails - 1);
        auto row = col % p;
        if (row >= static_cast<size_t>(num_rails))
            row = p - row;
        return row;
    }

    void zig_zag_write(crypto_board_t& crypto_board, const std::string& msg, const int num_rails) {
        for (size_t col = 0; col < msg.size(); ++col) {
            const size_t row = row_from_col(col, num_rails);
            crypto_board[row][col] = msg[col];
        }
    }

    std::string zig_zag_read(const crypto_board_t& crypto_board, const int num_rails) {
        assert(num_rails > 0);
        assert(crypto_board.size() == static_cast<size_t>(num_rails));
        const size_t col_count = crypto_board[0].size();
        std::string msg(col_count, 0);
        for (size_t col = 0; col < col_count; ++col) {
            const size_t row = row_from_col(col, num_rails);
            msg[col] = crypto_board[row][col];
        }
        return msg;
    }

    void zig_zag_init(crypto_board_t& crypto_board, const size_t textlength, const int num_rails) {
        for (size_t col = 0; col < textlength; ++col) {
            const size_t row = row_from_col(col, num_rails);
            crypto_board[row][col] = PLACE_HOLDER;
        }
    }
    std::string row_read(const crypto_board_t& crypto_board, const int num_rails) {
        assert(num_rails > 0);
        assert(crypto_board.size() == static_cast<size_t>(num_rails));
        const size_t col_count = crypto_board[0].size();
        std::string msg{};
        msg.reserve(col_count);
        for (auto& row : crypto_board) {
            for (auto& ch : row) {
                if (ch != UNUSED)
                    msg.push_back(ch);
            }
        }
        return msg;
    }
    void row_write(crypto_board_t& crypto_board, const std::string& msg) {
        size_t msg_index{ 0 };
        for (auto& row : crypto_board) {
            for (auto& ch : row) {
                if (ch == PLACE_HOLDER) {
                    ch = msg[msg_index++];
                }
            }
        }
    }

    std::string encode(const std::string& plaintext, int num_rails) {
        crypto_board_t crypto_board(num_rails, std::string(plaintext.size(), UNUSED));
        zig_zag_write(crypto_board, plaintext, num_rails);
        //std::cout << crypto_board << std::endl;
        return row_read(crypto_board, num_rails);
    }

    std::string decode(const std::string& ciphertext, int num_rails) {
        crypto_board_t crypto_board(num_rails, std::string(ciphertext.size(), UNUSED));
        zig_zag_init(crypto_board, ciphertext.length(), num_rails);
        row_write(crypto_board, ciphertext);
        //std::cout << crypto_board << std::endl;
        return zig_zag_read(crypto_board, num_rails);
    }

}  // namespace rail_fence_cipher
