#include "hexadecimal.h"

namespace hexadecimal {

// TODO: add your solution here
    unsigned long long convert(const std::string_view& hex_string) {
        unsigned long long result{ 0 };
        for (const auto& ch : hex_string) {
            result *= 16;
            switch (ch) {
            case '0': break;
            case '1': result += 1; break;
            case '2': result += 2; break;
            case '3': result += 3; break;
            case '4': result += 4; break;
            case '5': result += 5; break;
            case '6': result += 6; break;
            case '7': result += 7; break;
            case '8': result += 8; break;
            case '9': result += 9; break;
            case 'a': case 'A':  result += 10; break;
            case 'b': case 'B':  result += 11; break;
            case 'c': case 'C':  result += 12; break;
            case 'd': case 'D':  result += 13; break;
            case 'e': case 'E':  result += 14; break;
            case 'f': case 'F':  result += 15; break;
            default: return 0;
            }
        }
        return result;
    }

}  // namespace hexadecimal
