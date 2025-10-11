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

    char encrypt(const int a, const int b, char ch) {
        assert(is_coprime(a, M));
        if (std::isalpha(ch)) {
            // E(x) = (ai + b) mod m
            const auto i = std::tolower(ch) - 'a';
            const auto e_x = (a * i + b) % M;
            return 'a' + e_x;
        } else if (std::isdigit(ch)) {
            return ch;
        } else {
            return 0;
        }
    }

    std::string encode(const std::string text, const int a, const int b) {
        if (!is_coprime(a, M))
            throw std::invalid_argument("invlaid key");

        size_t count{ 0 };
        std::string code{};
        for (auto ch : text) {
            if (ch = encrypt(a, b, ch); ch != 0) {
                code.push_back(ch);
                if ((++count % GROUP) == 0)
                    code.push_back(' ');
            }
        }
        if (code.back() == ' ')
            code.pop_back();
        return code;
    }

    //////////////////////////////////////////////////////////

    int modular_multiplicative_inverse(int a, int m) {
        assert(is_coprime(a, M));
        for (int x = 1; x < m; ++x) {
            if (((a * x) % m) == 1)
                return x;
        }
        assert(false);
        return 0;
    }

    char decrypt(const int a, const int b, int mmi, char ch) {
        assert(is_coprime(a, M));
        if (std::isalpha(ch)) {
            // D(y) = (a^-1)(y - b) mod m
            const auto y = ch - 'a';
            auto d_y = (mmi * (y - b)) % M;
            if (d_y < 0)
                d_y = M + d_y;
            return 'a' + d_y;
        } else if (std::isdigit(ch)) {
            return ch;
        } else {
            return 0;
        }
    }

    std::string decode(const std::string code, const int a, const int b) {
        if (!is_coprime(a, M))
            throw std::invalid_argument("invlaid key");

        const int mmi = modular_multiplicative_inverse(a, M);
        std::string text{};
        for (auto ch : code) {
            if (ch = decrypt(a, b, mmi, ch); ch != 0)
                text.push_back(ch);
        }
        return text;
    }

}  // namespace affine_cipher
