#if !defined(ALPHAMETICS_H)
#define ALPHAMETICS_H
#include <map>
#include <optional>
#include <string>
namespace alphametics {

// TODO: add your solution here
    using alpha_digit_t = std::map<char, int>;
    std::optional<alpha_digit_t> solve(const std::string& puzzle);
}  // namespace alphametics

#endif  // ALPHAMETICS_H
