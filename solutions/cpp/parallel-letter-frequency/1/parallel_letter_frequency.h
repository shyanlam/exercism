#pragma once
#include <cinttypes>
#include <map>
#include <string_view>
#include <vector>

namespace parallel_letter_frequency {
    using letter_frequency_t = std::map<char, size_t>;
    letter_frequency_t frequency(const std::vector<std::string_view>& texts);
}
