#include "darts.h"
namespace darts {

// TODO: add your solution here
    constexpr double OUTER = 10.0 * 10.0;
    constexpr double MIDDLE = 5.0 * 5.0;
    constexpr double INNER = 1.0;
    int score(double x, double y) {
        const auto r_sq = x * x + y * y;
        if (r_sq > OUTER)
            return 0;
        else if (r_sq > MIDDLE)
            return 1;
        else if (r_sq > INNER)
            return 5;
        else
            return 10;
    }

}  // namespace darts