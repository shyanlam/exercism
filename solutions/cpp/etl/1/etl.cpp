#include "etl.h"
#include <cctype>

namespace etl {

// TODO: add your solution here
    letter_to_point_t transform(const point_to_letter_t& old) {
        letter_to_point_t result{};
        for (const auto& [point, letters] : old) {
            for (const auto& ch : letters) {
                result[std::tolower(ch)] = point;
            }
        }
        return result;
    }

}  // namespace etl
