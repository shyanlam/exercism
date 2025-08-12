#include "isbn_verifier.h"
#include <cctype>
#include <iterator>
#include <stdexcept>
#include <regex>
namespace isbn_verifier {

// TODO: add your solution here
    bool is_valid(const std::string& isbn) {
        static std::regex rx_isbn{ R"((\d)-?(\d)(\d)(\d)-?(\d)(\d)(\d)(\d)(\d)-?([0-9X]))" };

        int sum{ 0 };
        std::smatch match;
        if (std::regex_match(isbn, match, rx_isbn)) {
            if (match.size() < rx_isbn.mark_count() + 1)
                return false;

            const int matched_count = match.size();
            for (int pos = 10, n = 1; n < matched_count; ++n, --pos) {
                const auto ch = match[n].str()[0];
                if (ch == 'X') {
                    sum += pos * 10;
                } else {
                    sum += pos * (ch - '0');
                }
            }
            return  sum % 11 == 0;
        }
        return false;
    }

}  // namespace isbn_verifier