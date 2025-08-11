#include "perfect_numbers.h"
#include <stdexcept>
namespace perfect_numbers {
    long long aliquot_sum(long long value) {
        if (value == 1)
            return 0;

        long long aliquot_sum{ 1 };
        for (long long n = 2; n < value; ++n) {
            if (value % n == 0)
                aliquot_sum += n;
        }
        return aliquot_sum;
    }
    classification classify(long long value) {
        if (value < 1)
            throw std::domain_error("invalid value.");

        if (value < aliquot_sum(value))
            return classification::abundant;
        else if (value > aliquot_sum(value))
            return classification::deficient;
        else
            return classification::perfect;
    }

}  // namespace perfect_numbers
