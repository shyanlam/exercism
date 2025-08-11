#include "armstrong_numbers.h"
#include <cmath>
#include <string>
namespace armstrong_numbers {

// TODO: add your solution here
    bool is_armstrong_number(const long long value) {
        static auto power = [](long long value, int pow) -> long long {
            long long result = 1;
            for (int n = 0; n < pow; ++n)
                result *= value;
            return result;
        };

        const int digit_count = std::to_string(value).length();
        long long sum{ 0 };
        for (auto v = value; v; v = v / 10) {
            sum += power(v % 10, digit_count);
        }
        return sum == value;
    }

}  // namespace armstrong_numbers
