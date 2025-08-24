#include "resistor_color.h"
#include <cctype>
#include <stdexcept>
#include <algorithm>
namespace resistor_color {

    // TODO: add your solution here
    const std::vector<std::string> ColorNames{
        "black",
        "brown",
        "red",
        "orange",
        "yellow",
        "green",
        "blue",
        "violet",
        "grey",
        "white",
    };
    int color_code(std::string color_name) {
        std::transform(color_name.begin(), color_name.end(), color_name.begin(), std::tolower);
        if (auto it = std::find(ColorNames.cbegin(), ColorNames.cend(), color_name); it != ColorNames.cend()) {
            return static_cast<int>(std::distance(ColorNames.cbegin(), it));
        } else {
            throw std::domain_error("invalid color name.");
        }
    }
    std::vector<std::string> colors() {
        return ColorNames;
    }

}  // namespace resistor_color
