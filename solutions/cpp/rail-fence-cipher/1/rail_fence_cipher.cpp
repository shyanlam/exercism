#include "rail_fence_cipher.h"
#include <iostream>
#include <iomanip>
#include <iterator>
#include <numeric>
#include <vector>
namespace rail_fence_cipher {
    using row_t = std::vector<char>;
    using crypto_board_t = std::vector<row_t>;

    std::ostream& operator<<(std::ostream& os, const crypto_board_t& crypto_board) {
        for (auto& row : crypto_board) {
            for (auto& c : row) {
                os << std::setw(2) << (c ? c : '.');
            }
            os << std::endl;
        }
        os << std::endl;
        return os;
    }

    void encode_fill(crypto_board_t& crypto_board, const std::string& plaintext) {
        const size_t num_rails = crypto_board.size();

        int row{ 0 }, inc{ 1 };
        for (size_t n = 0; n < plaintext.size(); ++n) {
            crypto_board[row][n] = plaintext[n];
            if (row + inc == num_rails) {
                inc = -1;
            } else if (row + inc == -1) {
                inc = 1;
            }
            row += inc;
        }
    }

    std::string extract_cipher_text(const crypto_board_t& crypto_board) {
        std::string ciphertext{};
        const auto rows = crypto_board.size();
        ciphertext.reserve(rows > 0 ? crypto_board[0].size() : 0);
        for (auto& row : crypto_board) {
            for (auto ch : row) {
                if (ch != 0)
                    ciphertext.push_back(ch);
            }
        }
        return ciphertext;
    }

    std::string encode(const std::string& plaintext, int num_rails) {
        crypto_board_t crypto_board(num_rails, row_t(plaintext.length()));

        encode_fill(crypto_board, plaintext);
        //std::cout << crypto_board << std::endl;
        return extract_cipher_text(crypto_board);
    }

    void decode_fill(crypto_board_t& crypto_board, const std::string& ciphertext, const int num_rails) {
        size_t text_length = ciphertext.length();
        int row{ 0 }, inc{ 1 };
        for (size_t n = 0; n < text_length; ++n) {
            crypto_board[row][n] = '?';
            if (row + inc == num_rails)
                inc = -1;
            else if (row + inc == -1)
                inc = 1;
            row += inc;
        }

        size_t text_index{ 0 };
        for (auto& row : crypto_board) {
            for (auto& ch : row) {
                if (ch == '?')
                    ch = ciphertext[text_index++];
            }
        }
    }

    std::string extract_plain_text(const crypto_board_t& crypto_board, int num_rails) {
        std::string plaintext{};
        const auto rows = crypto_board.size();
        const auto col_count = rows > 0 ? crypto_board[0].size() : 0;
        plaintext.reserve(col_count);

        int row{ 0 }, inc{ 1 };
        for (size_t col = 0; col < col_count; ++col) {
            plaintext.push_back(crypto_board[row][col]);
            if (row + inc == num_rails)
                inc = -1;
            else if (row + inc == -1)
                inc = 1;
            row += inc;
        }
        return plaintext;
    }

    std::string decode(const std::string& ciphertext, int num_rails) {
        crypto_board_t crypto_board(num_rails, row_t(ciphertext.length()));
        decode_fill(crypto_board, ciphertext, num_rails);
        //std::cout << crypto_board << std::endl;
        return extract_plain_text(crypto_board, num_rails);
    }

}  // namespace rail_fence_cipher
