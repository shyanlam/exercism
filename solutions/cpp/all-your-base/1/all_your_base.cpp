#include "all_your_base.h"
#include <algorithm>
#include <stdexcept>
namespace all_your_base {

// TODO: add your solution here
    std::vector<unsigned int> convert(int from_base, const std::vector<unsigned int>& in_digits, int to_base) {
        if (from_base < 2 || to_base < 2)
            throw std::invalid_argument("invalid base.");

        unsigned long long base10{ 0 };
        for (auto digit : in_digits) {
            if (digit >= static_cast<unsigned int>(from_base))
                throw std::invalid_argument("invalid value for base.");
            base10 *= from_base;
            base10 += digit;
        }

        std::vector<unsigned int> result{};
        while (base10) {
            result.push_back(base10 % to_base);
            base10 /= to_base;
        }
        std::reverse(result.begin(), result.end());
        return result;
    }

}  // namespace all_your_base
