#include "alphametics.h"
#include <algorithm>
#include <cassert>
#include <cctype>
#include <optional>
#include <set>
#include <vector>

namespace alphametics {

// TODO: add your solution here
    using term_t = std::string;
    using terms_t = std::vector<term_t>;
    using value_t = long long;
    constexpr auto EQUAL_TO = "==";
    const auto EQUAL_TO_LENGTH = std::strlen(EQUAL_TO);
    constexpr auto PLUS = "+";
    static constexpr auto npos = std::string::npos;

    std::vector<std::string> skip(std::string str, const std::string& delimiter) {
        std::vector<std::string> result;
        while (!str.empty()) {
            auto pos = str.find(delimiter);
            result.push_back(str.substr(0, pos));
            if (pos != npos) {
                pos += delimiter.length();
            }
            str.erase(0, pos);
        }
        return result;
    }

    class alphametics_solver_t {
    public:
        bool parse(std::string puzzle) {
            puzzle.erase(std::remove_if(puzzle.begin(), puzzle.end(), [](char ch) { return std::isspace(ch); }), puzzle.end());
            const auto left_right = skip(puzzle, EQUAL_TO);
            const auto terms = skip(left_right[0], PLUS);
            const auto& sum = left_right[1];

            if (terms.size() < 2)
                return false;
            for (const auto& term : terms) {
                if (sum.length() < term.length())
                    return false;

                update_info(term, 1);
            }
            update_info(sum, -1);
            return true;
        }

        std::optional<alpha_digit_t> solve() {
            std::vector<int> digits{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
            alpha_digit_t prev_value;
            do {
                if (set_alpha_digit(digits) && _alpha_digit != prev_value) {
                    prev_value = _alpha_digit;
                    if (is_solved())
                        return _alpha_digit;
                }
            } while (std::next_permutation(digits.begin(), digits.end()));
            return std::nullopt;
        }

    private:
        void update_info(const std::string& term, long long multiplier) {
            for (auto rit = term.rbegin(); rit != term.rend(); ++rit, multiplier *= 10) {
                _consolidated_form[*rit] += multiplier;
                _alpha_digit.emplace(std::pair(*rit, 0));
            }
            if (term.length() > 1)
                _most_significatn.insert(term[0]);
        }

        bool set_alpha_digit(const std::vector<int>& digits) {
            size_t index = digits.size() - _alpha_digit.size();
            for (auto& [ch, digit] : _alpha_digit) {
                digit = digits[index++];
                if (digit == 0 && _most_significatn.find(ch) != _most_significatn.end())
                    return false;
            }
            return true;
        }

        bool is_solved() const {
            assert(_alpha_digit.size() == _consolidated_form.size());
            value_t sum{ 0 };
            for (const auto [ch, val] : _consolidated_form) {
                sum += _alpha_digit.at(ch) * val;
            }
            return sum == 0;
        }

    private:
        alpha_digit_t _alpha_digit;
        std::set<char> _most_significatn;
        std::map<char, value_t> _consolidated_form;
    };

    std::optional<alpha_digit_t> solve(const std::string& puzzle) {
        alphametics_solver_t solver;

        std::optional<alpha_digit_t> result;
        if (solver.parse(puzzle)) {
            result = solver.solve();
        }
        return result;
    }

}  // namespace alphametics
