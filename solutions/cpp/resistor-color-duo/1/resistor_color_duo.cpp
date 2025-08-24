#include "resistor_color_duo.h"
#include <algorithm>
#include <stdexcept>
#include <cctype>
#include <map>
namespace resistor_color_duo {

// TODO: add your solution here
    int value(const std::initializer_list<std::string>& colors) {
        const static std::map<std::string, int> COLOR_VALUE {
            { "black",  0 },
            { "brown",  1 },
            { "red",    2 },
            { "orange", 3 },
            { "yellow", 4 },
            { "green",  5 },
            { "blue",   6 },
            { "violet", 7 },
            { "grey",   8 },
            { "white",  9 },
        };
        const int MAX_BAND_COUNT = 2;

        int band_count{ 0 };
        int resistence{ 0 };
        for (auto color : colors) {
            std::transform(color.begin(), color.end(), color.begin(),
                           [](const char ch) -> char { return static_cast<char>(std::tolower(ch));  });
            if (auto cit = COLOR_VALUE.find(color); cit != COLOR_VALUE.cend()) {
                resistence = resistence * 10 + cit->second;
                if (++band_count == MAX_BAND_COUNT)
                    break;
            } else {
                throw std::domain_error("invalid color name.");
            }
        }
        return resistence;
    }

}  // namespace resistor_color_duo
