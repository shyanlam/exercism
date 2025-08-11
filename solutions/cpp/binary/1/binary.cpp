#include "binary.h"

namespace binary {

// TODO: add your solution here
    unsigned long long convert(const std::string_view binary_string) {
        const int len = binary_string.length();
        unsigned long long result{ 0 };
        int pow = binary_string.length() - 1;
        for (auto cit = binary_string.begin(); cit != binary_string.end(); ++cit, --pow) {
            const auto& ch = *cit;
            if (ch == '1') {
                result += (1LL << pow);
            } else if (ch != '0') {
                result = 0;
                break;
            }
        }
        return result;
    }

}  // namespace binary
