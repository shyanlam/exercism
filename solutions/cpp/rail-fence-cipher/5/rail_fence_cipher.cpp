#include "rail_fence_cipher.h"
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
namespace rail_fence_cipher {
    constexpr auto UNUSED = '.';
    constexpr auto PLACE_HOLDER = '?';
    using crypto_board_t = std::vector<std::string>;

    size_t row_from_col(size_t col, int num_rails) {
        auto p = 2 * (num_rails - 1);
        auto row = col % p;
        if (row >= static_cast<size_t>(num_rails))
            row = p - row;
        return row;
    }

    using rail_index_t = std::vector<std::vector<size_t>>;
    rail_index_t create_rail_indexes(const size_t message_length, const int num_rails) {
        rail_index_t rail_indexes(num_rails);
        for (size_t n = 0; n < message_length; ++n) {
            auto row = row_from_col(n, num_rails);
            rail_indexes[row].emplace_back(n);
        }
        return rail_indexes;
    }

    std::string encode(const std::string& plaintext, int num_rails) {
        auto rail_indexes = create_rail_indexes(plaintext.length(), num_rails);
        std::string ciphertext(plaintext.length(), 0);
        size_t cipher_index{ 0 };
        for (const auto& indexes : rail_indexes) {
            for (const auto& index : indexes) {
                ciphertext[cipher_index++] = plaintext[index];
            }
        }
        return ciphertext;
    }

    std::string decode(const std::string& ciphertext, int num_rails) {
        auto rail_indexes = create_rail_indexes(ciphertext.length(), num_rails);
        size_t cipher_index{ 0 };
        std::string plaintext(ciphertext.length(), 0);
        for (const auto& indexes : rail_indexes) {
            for (const auto& index : indexes) {
                plaintext[index] = ciphertext[cipher_index++];
            }
        }
        return plaintext;
    }

}  // namespace rail_fence_cipher
