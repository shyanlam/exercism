#include "binary.h"

namespace binary {

// TODO: add your solution here
    unsigned long long convert(const std::string_view binary_string) {
        unsigned long long result{ 0 };
        for (const auto& ch : binary_string) {
            result <<= 1;
            switch (ch) {
            case '1':
                result |= 1;
                [[fallthrough]];
            case '0':
                break;
            default:
                return 0;
            }
        }
        return result;
    }

}  // namespace binary
