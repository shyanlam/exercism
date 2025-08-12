#include "darts.h"
#include <cmath>
namespace darts {

// TODO: add your solution here
    constexpr double OUTER = 10.0;
    constexpr double MIDDLE = 5.0;
    constexpr double INNER = 1.0;
    int score(double x, double y) {
        const auto r = std::sqrt(x * x + y * y);
        if (r > OUTER)
            return 0;
        else if (r > MIDDLE)
            return 1;
        else if (r > INNER)
            return 5;
        else
            return 10;
    }

}  // namespace darts