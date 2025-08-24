#include "run_length_encoding.h"
#include <regex>
#include <sstream>
namespace run_length_encoding {

// TODO: add your solution here
    std::string encode(const std::string& text) {
        std::stringstream code{};

        for (auto cit = text.begin(), citNext = cit; cit != text.end(); cit = citNext) {
            citNext = std::find_if(cit, text.end(), [cit](char c) -> bool { return c != *cit; });
            const int count = std::distance(cit, citNext);
            if (count > 1)
                code << count;
            code << *cit;
        }

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
