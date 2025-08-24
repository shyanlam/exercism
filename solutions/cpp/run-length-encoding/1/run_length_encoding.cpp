#include "run_length_encoding.h"
#include <regex>
#include <sstream>
namespace run_length_encoding {

// TODO: add your solution here
    std::string encode(const std::string& text) {
        std::stringstream code{};

        auto out_count_char = [&code](int count, char ch) {
            if (ch != 0 && count > 0) {
                if (count > 1)
                    code << count;
                code << ch;
            }
        };

        int count{ 0 };
        char ch_current{};
        for (auto& ch : text) {
            if (ch == ch_current) {
                ++count;
            } else {
                out_count_char(count, ch_current);
                ch_current = ch;
                count = 1;
            }
        }
        out_count_char(count, ch_current);
        return code.str();
    }

    std::string decode(const std::string& code) {
        auto get_count = [](const std::string& value) -> int {
            return value.empty() ? 1 : std::stol(value);
        };
        static std::regex count_ch(R"((\d*)(.))");
        std::stringstream result{};
        auto begin = std::sregex_iterator(code.begin(), code.end(), count_ch);
        auto end = std::sregex_iterator();
        for (auto it = begin; it != end; ++it) {
            auto match = *it;
            result << std::string(get_count(match[1].str()), match[2].str()[0]);
        }
        return result.str();
    }

}  // namespace run_length_encoding
