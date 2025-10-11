#include "affine_cipher.h"
#include <cassert>
#include <cctype>
#include <stdexcept>
#include <string>
#include <numeric>
namespace affine_cipher {

// TODO: add your solution here
    constexpr int M = 26;
    constexpr int GROUP = 5;

    bool is_coprime(int a, int b) {
        return std::gcd(a, b) == 1;
    }

    std::string encode(const std::string text, const int a, const int b) {
        if (!is_coprime(a, M))
            throw std::invalid_argument("invlaid key");

        auto encrypt = [a, b](char ch) -> char {
            const auto i = ch - 'a';
            const auto encrypted_value = (a * i + b) % M;
            return std::isdigit(ch) ? ch : 'a' + encrypted_value;
            };
        size_t count{ 0 };
        std::string code{};
        for (auto ch : text) {
            if (!std::isalnum(ch))
                continue;

            code.push_back(encrypt(static_cast<char>(std::tolower(ch))));
            if ((++count % GROUP) == 0)
                code.push_back(' ');
        }
        if (code.back() == ' ')
            code.pop_back();
        return code;
    }

    int modular_multiplicative_inverse(int a, int m) {
        for (int x = 1; x < m; ++x) {
            if (((a * x) % m) == 1)
                return x;
        }
        assert(false);
        return 0;
    }
    std::string decode(const std::string code, const int a, const int b) {
        if (!is_coprime(a, M))
            throw std::invalid_argument("invlaid key");

        const int mmi = modular_multiplicative_inverse(a, M);
        auto decrypt = [a, b, mmi](char c) -> char {
            auto y = c - 'a';
            auto decrypted_value = (M + ((mmi * (y - b)) % M)) % M;
            return std::isdigit(c) ? c : 'a' + decrypted_value;
            };

        std::string text{};
        for (auto ch : code) {
            if (!std::isspace(ch))
                text.push_back(decrypt(ch));
        }
        return text;
    }

}  // namespace affine_cipher
