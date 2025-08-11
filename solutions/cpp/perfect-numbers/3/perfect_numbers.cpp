#include "perfect_numbers.h"
#include <stdexcept>
namespace perfect_numbers {
    classification classify(long long value) {
        if (value < 1)
            throw std::domain_error("invalid value.");

        long long aliquot_sum{ 0 };
        for (long long n = 1; n <= value / 2; ++n) {
            if (value % n == 0)
                aliquot_sum += n;
        }

        if (value < aliquot_sum)
            return classification::abundant;
        else if (value > aliquot_sum)
            return classification::deficient;
        else
            return classification::perfect;
    }

}  // namespace perfect_numbers
