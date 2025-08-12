#include "largest_series_product.h"
#include <cctype>
#include <stdexcept>
namespace largest_series_product {

// TODO: add your solution here
    long long series_product(const std::string& series) {
        long long product{ 1 };
        for (auto ch : series) {
            if (!std::isdigit(ch))
                throw std::domain_error("invalid value in series.");
            if (ch == '0')
                return 0;
            else
                product *= ch - '0';
        }
        return product;
    }

    long long largest_product(const std::string& input, const int span) {
        const auto input_length = input.length();
        if (static_cast<size_t>(span) > input_length)
            throw std::domain_error("invalid span.");

        long long largest_product{ 0 };
        const auto last_index = input_length - span + 1;
        for (size_t n = 0; n < last_index; ++n) {
            if (auto product = series_product(input.substr(n, span)); product > largest_product) {
                largest_product = product;
            }
        }
        return largest_product;
    }

}  // namespace largest_series_product