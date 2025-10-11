#include "affine_cipher.h"
#include <cassert>
#include <cctype>
#include <stdexcept>
#include <string>
#include <numeric>
#include <map>
namespace affine_cipher {

// TODO: add your solution here
    constexpr int M = 26;
    constexpr int GROUP = 5;

    class affine_table_t {
    public:
        affine_table_t(int a, int b) {
            for (int i = 0; i < ALPHA_LENGTH; ++i) {
                // E(x) = (ai + b) mod m
                const auto code = (a * i + b) % ALPHA_LENGTH;
                const char lower = 'a' + i;
                const char upper = 'A' + i;
                const char crypt = 'a' + code;
                encoding_table[lower] = crypt;
                encoding_table[upper] = crypt;
                decoding_table[crypt] = lower;
            }
            for (int d = '0'; d <= '9'; ++d) {
                encoding_table[d] = d;
                decoding_table[d] = d;
            }
        }
        char encode(char ch) const {
            auto it = encoding_table.find(ch);
            return it == encoding_table.end() ? 0 : it->second;
        }
        char decode(char ch) const {
            auto it = decoding_table.find(ch);
            return it == decoding_table.end() ? 0 : it->second;
        }

    private:
        static constexpr int ALPHA_LENGTH{ 'z' - 'a' + 1 };
        std::map<char, char> encoding_table;
        std::map<char, char> decoding_table;
    };

    bool is_coprime(int a, int b) {
        return std::gcd(a, b) == 1;
    }

    char encrypt(const int a, const int b, char ch) {
        assert(is_coprime(a, M));
        if (std::isalpha(ch)) {
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

        affine_table_t table(a, b);
        size_t count{ 0 };
        std::string code{};
        for (auto ch : text) {
            if (ch = table.encode(ch); ch != 0) {
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

    std::string decode(const std::string code, const int a, const int b) {
        if (!is_coprime(a, M))
            throw std::invalid_argument("invlaid key");

        affine_table_t table(a, b);

        std::string text{};
        for (auto ch : code) {
            if (ch = table.decode(ch); ch != 0)
                text.push_back(ch);
        }
        return text;
    }

}  // namespace affine_cipher
