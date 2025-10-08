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
            std::for_each(std::execution::par, text.begin(), text.end(),
                          [&](char c) {
                              if (std::isalpha(c)) {
                                  std::lock_guard<std::mutex> guard(m);
                                  ++result[static_cast<char>(std::tolower(c))];
                              }
                          });
            };

        for_each(std::execution::par, texts.begin(), texts.end(), text_frequency);
        return result;
    }
}
