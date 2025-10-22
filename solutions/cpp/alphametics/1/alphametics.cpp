#include "alphametics.h"
#include <algorithm>
#include <cassert>
#include <cctype>
#include <optional>
#include <set>
#include <vector>
#include <boost/algorithm/string.hpp>

namespace alphametics {

// TODO: add your solution here

    using term_t = std::string;
    using terms_t = std::vector<term_t>;

    constexpr auto EQUAL_TO = "==";
    const auto EQUAL_TO_LENGTH = std::strlen(EQUAL_TO);
    constexpr auto PLUS = "+";
    static constexpr auto npos = std::string::npos;

    bool parse(const std::string& puzzle, terms_t& terms, term_t& sum) {
        auto pos = puzzle.find(EQUAL_TO);
        if (pos == npos)
            return false;

        sum = puzzle.substr(pos + EQUAL_TO_LENGTH);
        boost::trim(sum);
        auto lhs = puzzle.substr(0, pos);
        boost::split(terms, lhs, boost::is_any_of(PLUS));
        if (terms.size() < 2)
            return false;

        for (auto& term : terms) {
            boost::trim(term);
            if (term.length() > sum.length())
                return false;
        }

        return true;
    }

    void update_alphas(const term_t& term, alpha_digit_t& alpha_digit, std::set<char>& most_significant) {
        for (size_t n = 0; n < term.length(); ++n) {
            alpha_digit[term[n]] = 0;;
        }
        if (term.length() > 1)
            most_significant.insert(term[0]);
    }

    bool get_alpha_digit(alpha_digit_t& alpha_digit, const std::vector<int>& digits, const std::set<char>& most_significant) {
        auto alpha_count = alpha_digit.size();
        size_t index = digits.size() - alpha_count;
        for (auto& [alpha, digit] : alpha_digit) {
            digit = digits[index++];
            if ((most_significant.find(alpha) != most_significant.end()) && (digit == 0))
                return false;
        }
        return true;
    }

    long long get_term_value(const term_t& term, const alpha_digit_t& alpha_digit) {
        long long result{ 0 };
        for (size_t n = 0; n < term.length(); ++n) {
            const auto ch = term[n];
            result = result * 10 + alpha_digit.at(ch);
        }
        return result;
    }

    bool is_solved(const terms_t& terms, const term_t& sum, const alpha_digit_t& alpha_digit) {
        long long result{ 0 };
        for (const auto& term : terms) {
            result += get_term_value(term, alpha_digit);
        }
        return result == get_term_value(sum, alpha_digit);
    }

    std::optional<alpha_digit_t> solve(const std::string& puzzle) {
        terms_t terms;
        term_t sum;
        if (!parse(puzzle, terms, sum))
            return std::nullopt;

        alpha_digit_t alpha_value{}, previous_value{};
        std::set<char> most_significant{};
        update_alphas(sum, alpha_value, most_significant);
        for (const auto& term : terms) {
            update_alphas(term, alpha_value, most_significant);
        }
        if (alpha_value.size() > 10)
            return std::nullopt;

        std::vector<int> digits{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        do {
            if (get_alpha_digit(alpha_value, digits, most_significant)) {
                if (alpha_value != previous_value) {
                    previous_value = alpha_value;
                    if (is_solved(terms, sum, alpha_value)) {
                        return alpha_value;
                    }
                }
            }
        } while (std::next_permutation(digits.begin(), digits.end()));

        return std::nullopt;
    }

}  // namespace alphametics
