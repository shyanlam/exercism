#include "parallel_letter_frequency.h"
#include <algorithm>
#include <cctype>
#include <execution>
#include <mutex>

namespace parallel_letter_frequency {
    std::map<char, size_t> frequency(const std::vector<std::string_view>& texts) {
        letter_frequency_t result{};
        std::mutex m;

        auto text_frequency = [&](const std::string_view& text) {
            letter_frequency_t local{};
            for (auto c : text) {
                if (std::isalpha(c)) {
                    c = static_cast<char>(std::tolower(c));
                    ++local[c];
                }
            }
            std::lock_guard<std::mutex> guard(m);
            for (const auto [ch, count] : local) {
                result[ch] += count;
            }
            };

        for_each(std::execution::par, texts.begin(), texts.end(), text_frequency);
        return result;
    }
}
